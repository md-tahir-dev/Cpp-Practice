#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

enum AccountType
{
    Bronze,
    Gold,
    Business
};
enum UserRole
{
    Client,
    Employee,
    CEO
};
enum Role
{
    User,
    Admin
};
string getTodayDate()
{
    char buffer[11];
    time_t now = time(0);
    strftime(buffer, sizeof buffer, "%Y-%m-%d", localtime(&now));
    return buffer;
}

void logTransaction(const string &id, double amount, const string &type,
                    const string &receiver = "")
{
    ofstream file("transactions.txt", ios::app);
    if (!file)
    {
        cerr << "Error: could not open transactions.txt for writing.\n";
        return;
    }
    file << getTodayDate() << ',' << id << ',' << setprecision(17) << amount
         << ',' << type << ',' << receiver << '\n';
}

// ---------------------------------------------------------------- accounts

class Account
{
protected:
    string accountID, password, lastTransactionDate;
    double balance, dailyLimit, dailyWithdrawn = 0;
    bool isApproved, isFrozen;
    AccountType type;

    bool active() const { return isApproved && !isFrozen; }
    virtual bool canSendTo(const Account *) const { return true; }

    // Shared by withdraw and transfer: balance check + daily limit.
    bool canDebit(double amount, const string &action)
    {
        if (amount > balance)
        {
            cout << action << " denied. Insufficient balance.\n";
            return false;
        }
        const string today = getTodayDate();
        if (today != lastTransactionDate)
        {
            dailyWithdrawn = 0;
            lastTransactionDate = today;
        }
        if (dailyWithdrawn + amount > dailyLimit)
        {
            cout << action << " denied. Daily limit exceeded.\n";
            return false;
        }
        return true;
    }

public:
    Account(const string &id, const string &pass, double initialBalance,
            AccountType accountType, bool approved, bool frozen)
        : accountID(id), password(pass), balance(initialBalance),
          isApproved(approved), isFrozen(frozen), type(accountType)
    {
        static const double limits[] = {100000, 500000, 20000000};
        dailyLimit = limits[type];
    }

    virtual ~Account() = default;
    virtual void displayInfo() const = 0;
    virtual void write(ostream &out) const = 0;
    const string &getPassword() const
    {
        return password;
    }
    bool login(const string &id, const string &pass) const
    {
        return accountID == id && password == pass && active();
    }
    const string &getID() const { return accountID; }
    bool isActive() const { return active(); }
    AccountType getType() const { return type; }
    void setApproved(bool value) { isApproved = value; }

    void deposit(double amount)
    {
        if (amount <= 0 || !active())
        {
            cout << "Deposit denied. Check the amount and account status.\n";
            return;
        }
        balance += amount;
        logTransaction(accountID, amount, "Deposit");
        cout << "Deposited " << amount << " PKR. New balance: " << balance << '\n';
    }

    void withdraw(double amount)
    {
        if (amount <= 0 || !active())
        {
            cout << "Withdrawal denied. Check the amount and account status.\n";
            return;
        }
        if (!canDebit(amount, "Withdrawal"))
            return;
        balance -= amount;
        dailyWithdrawn += amount;
        logTransaction(accountID, amount, "Withdrawal");
        cout << "Withdrew " << amount << " PKR. New balance: " << balance << '\n';
    }

    void transfer(Account *to, double amount)
    {
        if (!to || to == this || amount <= 0 || !active() || !to->active() ||
            !canSendTo(to))
        {
            cout << "Transfer denied. Check the destination, amount, and account status "
                    "(companies can only transfer to user accounts).\n";
            return;
        }
        if (!canDebit(amount, "Transfer"))
            return;
        balance -= amount;
        to->balance += amount;
        dailyWithdrawn += amount;
        logTransaction(accountID, amount, "Transfer", to->accountID);
        cout << "Transferred " << amount << " PKR to " << to->accountID << ".\n";
    }
};

class UserAccount : public Account
{
    string fullName, address, phone, cnic, companyID;
    UserRole role;

public:
    UserAccount(const string &id, const string &pass, const string &name,
                const string &addr, const string &phoneNumber,
                const string &cnicNumber, AccountType accountType,
                double initialBalance = 0, bool approved = false,
                bool frozen = false, UserRole userRole = Client,
                const string &company = "")
        : Account(id, pass, initialBalance, accountType, approved, frozen),
          fullName(name), address(addr), phone(phoneNumber), cnic(cnicNumber),
          companyID(company), role(userRole) {}

    const string &getFullName() const { return fullName; }
    const string &getCNIC() const { return cnic; }
    const string &getCompanyID() const { return companyID; }
    UserRole getRole() const { return role; }
    void setRole(UserRole newRole) { role = newRole; }

    void displayInfo() const override
    {
        static const char *roleNames[] = {"Client", "Employee", "CEO"};
        cout << "User: " << fullName << " | ID: " << accountID
             << " | Type: " << (type == Bronze ? "Bronze" : "Gold")
             << " | Role: " << roleNames[role];
        if (!companyID.empty())
            cout << " (" << companyID << ")";
        cout << " | Balance: " << balance
             << " | Status: " << (isApproved ? "Approved" : "Pending")
             << (isFrozen ? " (Frozen)" : "") << '\n';
    }
    void setCompanyID(const string &id)
    {
        companyID = id;
    }
    void write(ostream &out) const override
    {
        out << quoted(accountID) << ' ' << quoted(password) << ' '
            << setprecision(17) << balance << ' ' << type << ' ' << isApproved
            << ' ' << isFrozen << ' ' << quoted(fullName) << ' ' << quoted(address)
            << ' ' << quoted(phone) << ' ' << quoted(cnic) << ' ' << role << '\n';
    }
};
class CompanyAccount : public Account
{
    string companyName, companyAddress, taxNumber;

    bool canSendTo(const Account *to) const override
    {
        return dynamic_cast<const UserAccount *>(to) != nullptr;
    }

public:
    CompanyAccount(const string &id, const string &pass, const string &name,
                   const string &addr, const string &tax,
                   double initialBalance = 0, bool approved = false,
                   bool frozen = false)
        : Account(id, pass, initialBalance, Business, approved, frozen),
          companyName(name), companyAddress(addr), taxNumber(tax) {}
    void displayInfo() const override
    {
        cout << "Company: " << companyName << " | ID: " << accountID
             << " | Address: " << companyAddress << " | Tax: " << taxNumber
             << " | Balance: " << balance
             << " | Status: " << (isApproved ? "Approved" : "Pending")
             << (isFrozen ? " (Frozen)" : "") << '\n';
    }

    void write(ostream &out) const override
    {
        out << quoted(accountID) << ' ' << quoted(password) << ' '
            << setprecision(17) << balance << ' ' << isApproved << ' '
            << isFrozen << ' ' << quoted(companyName) << ' '
            << quoted(companyAddress) << ' ' << quoted(taxNumber) << '\n';
    }
};

// ------------------------------------------------------- cards and loans

struct Card
{
    string accountID, cardNumber, pin;
    int failedAttempts = 0;
    bool locked = false;

    bool verifyPIN(const string &entered)
    {
        if (locked)
            return false;
        if (entered == pin)
        {
            failedAttempts = 0;
            return true;
        }
        if (++failedAttempts >= 3)
            locked = true;
        return false;
    }
};

struct LoanRequest
{
    string companyID;
    double amount;
    string status = "Pending";
};

struct AdminRecord
{
    string id, password, fullName, cnic, phone, address;
};
// ---------------------------------------------------------- persistence
void updateLogins(Role role, const vector<pair<string, string>> &rows);
void saveCompanyEmployees(const vector<unique_ptr<Account>> &accounts);

void saveAccounts(const vector<unique_ptr<Account>> &accounts)
{
    ofstream users("users.txt"), companies("companies.txt");
    if (!users || !companies)
    {
        cerr << "Error: could not save account files.\n";
        return;
    }
    for (const auto &account : accounts)
    {
        account->write(account->getType() == Business ? companies : users);
    }
    vector<pair<string, string>> rows;
    for (const auto &account : accounts)
        rows.emplace_back(account->getID(), account->getPassword());
    updateLogins(User, rows);
    saveCompanyEmployees(accounts);
}

void loadUsers(vector<unique_ptr<Account>> &accounts)
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, pass, name, address, phone, cnic;
        double balance;
        int type, approved, frozen;
        if (!(row >> quoted(id) >> quoted(pass) >> balance >> type >> approved >>
              frozen >> quoted(name) >> quoted(address) >> quoted(phone) >>
              quoted(cnic)) ||
            (type != Bronze && type != Gold) || balance < 0)
        {
            cerr << "Warning: skipping an invalid users.txt record.\n";
            continue;
        }

        // New: optional fields, so old users.txt files still load
        int role = Client;
        if (!(row >> role) || role < Client || role > CEO)
            role = Client;

        accounts.push_back(make_unique<UserAccount>(
            id, pass, name, address, phone, cnic, static_cast<AccountType>(type),
            balance, approved != 0, frozen != 0, static_cast<UserRole>(role)));
    }
}

void loadCompanies(vector<unique_ptr<Account>> &accounts)
{
    ifstream file("companies.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, pass, name, address, tax;
        double balance;
        int approved, frozen;
        if (!(row >> quoted(id) >> quoted(pass) >> balance >> approved >> frozen >>
              quoted(name) >> quoted(address) >> quoted(tax)) ||
            balance < 0)
        {
            cerr << "Warning: skipping an invalid companies.txt record.\n";
            continue;
        }
        accounts.push_back(make_unique<CompanyAccount>(
            id, pass, name, address, tax, balance, approved != 0, frozen != 0));
    }
}

void saveCards(const vector<Card> &cards)
{
    ofstream file("cards.txt");
    if (!file)
    {
        cerr << "Error: could not open cards.txt for writing.\n";
        return;
    }
    for (const Card &card : cards)
        file << quoted(card.accountID) << ' ' << quoted(card.cardNumber) << ' '
             << quoted(card.pin) << ' ' << card.failedAttempts << ' '
             << card.locked << '\n';
}

void loadCards(vector<Card> &cards)
{
    ifstream file("cards.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, number, pin;
        int failures, locked;
        if (!(row >> quoted(id) >> quoted(number) >> quoted(pin) >> failures >> locked))
        {
            cerr << "Warning: skipping an invalid cards.txt record.\n";
            continue;
        }
        cards.push_back({id, number, pin, failures, locked != 0});
    }
}

void saveLoans(const vector<LoanRequest> &loans)
{
    ofstream file("loans.txt");
    if (!file)
    {
        cerr << "Error: could not open loans.txt for writing.\n";
        return;
    }
    for (const LoanRequest &loan : loans)
        file << quoted(loan.companyID) << ' ' << setprecision(17) << loan.amount
             << ' ' << quoted(loan.status) << '\n';
}

void loadLoans(vector<LoanRequest> &loans)
{
    ifstream file("loans.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, status;
        double amount;
        if (!(row >> quoted(id) >> amount >> quoted(status)) || amount <= 0)
        {
            cerr << "Warning: skipping an invalid loans.txt record.\n";
            continue;
        }
        loans.push_back({id, amount, status});
    }
}

void saveCompanyEmployees(const vector<unique_ptr<Account>> &accounts)
{
    ofstream file("companies_employees.txt");
    if (!file)
    {
        cerr << "Error: could not open companies_employees.txt for writing.\n";
        return;
    }
    for (const auto &account : accounts)
        if (auto *user = dynamic_cast<const UserAccount *>(account.get()))
            if (!user->getCompanyID().empty())
                file << user->getCompanyID() << ", " << user->getID() << '\n';
}

void loadCompanyEmployees(vector<unique_ptr<Account>> &accounts)
{
    ifstream file("companies_employees.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string companyID, employeeID;
        if (!getline(row, companyID, ',') || !(row >> ws) || !getline(row, employeeID))
            continue;
        for (const auto &account : accounts)
            if (account->getID() == employeeID)
                if (auto *user = dynamic_cast<UserAccount *>(account.get()))
                    user->setCompanyID(companyID);
    }
}

// ---- login.txt: every user/company (Role::User) and admin (Role::Admin)
struct LoginRecord
{
    string id, password;
    Role role;
};

vector<LoginRecord> loadLogins()
{
    vector<LoginRecord> logins;
    ifstream file("login.txt");
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        LoginRecord r;
        int role;
        if (row >> quoted(r.id) >> quoted(r.password) >> role &&
            (role == User || role == Admin))
        {
            r.role = static_cast<Role>(role);
            logins.push_back(r);
        }
    }
    return logins;
}

// Replaces all rows of one role, keeping the other role's rows untouched.
void updateLogins(Role role, const vector<pair<string, string>> &rows)
{
    vector<LoginRecord> logins = loadLogins();
    logins.erase(remove_if(logins.begin(), logins.end(),
                           [role](const LoginRecord &r)
                           { return r.role == role; }),
                 logins.end());
    for (const auto &row : rows)
        logins.push_back({row.first, row.second, role});

    ofstream file("login.txt");
    if (!file)
    {
        cerr << "Error: could not open login.txt for writing.\n";
        return;
    }
    for (const LoginRecord &r : logins)
        file << quoted(r.id) << ' ' << quoted(r.password) << ' ' << r.role << '\n';
}

bool authenticate(const string &id, const string &pass, Role role)
{
    for (const LoginRecord &r : loadLogins())
        if (r.id == id && r.password == pass && r.role == role)
            return true;
    return false;
}

void saveAdmins(const vector<AdminRecord> &admins)
{
    ofstream file("admin.txt");
    if (!file)
    {
        cerr << "Error: could not open admin.txt for writing.\n";
        return;
    }
    vector<pair<string, string>> rows;
    for (const AdminRecord &a : admins)
    {
        file << quoted(a.id) << ' ' << quoted(a.password) << ' '
             << quoted(a.fullName) << ' ' << quoted(a.cnic) << ' '
             << quoted(a.phone) << ' ' << quoted(a.address) << '\n';
        rows.emplace_back(a.id, a.password);
    }
    updateLogins(Admin, rows);
}

void loadAdmins(vector<AdminRecord> &admins)
{
    ifstream file("admin.txt");
    if (!file)
    {
        cerr << "Error: admin.txt not found.\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        AdminRecord a;
        if (!(row >> quoted(a.id) >> quoted(a.password)))
            continue; // blank or invalid line
        // Detail fields are optional so old "id pass" files still load
        if (!(row >> quoted(a.fullName) >> quoted(a.cnic) >> quoted(a.phone) >>
              quoted(a.address)))
            a.fullName = a.cnic = a.phone = a.address = "";
        admins.push_back(a);
    }
}

// ------------------------------------------------------------- helpers

// Exits cleanly on end-of-input so menus can't loop forever.
string readLine(const string &prompt)
{
    cout << prompt;
    string input;
    if (!getline(cin, input))
        exit(0);
    return input;
}

template <typename T>
bool readValue(const string &prompt, T &value)
{
    istringstream stream(readLine(prompt));
    char extra;
    return (stream >> value) && !(stream >> extra);
}

Account *findAccount(vector<unique_ptr<Account>> &accounts, const string &id)
{
    for (const auto &account : accounts)
        if (account->getID() == id)
            return account.get();
    return nullptr;
}

bool canManageCompany(vector<unique_ptr<Account>> &accounts,
                      const string &companyID, const string &actorID)
{
    if (actorID.empty())
        return true;
    auto *user = dynamic_cast<UserAccount *>(findAccount(accounts, actorID));
    return user && user->getCompanyID() == companyID && user->getRole() == CEO;
}
// Returns the 13 digits, or "" if the input isn't a valid CNIC.
string normalizeCNIC(const string &input)
{
    string digits;
    for (char c : input)
    {
        if (c >= '0' && c <= '9')
            digits += c;
        else if (c != '-')
            return "";
    }
    return digits.size() == 13 ? digits : "";
}

bool cnicExists(const vector<unique_ptr<Account>> &accounts, const string &cnic)
{
    for (const auto &account : accounts)
        if (auto *user = dynamic_cast<const UserAccount *>(account.get()))
            if (user->getCNIC() == cnic)
                return true;
    return false;
}
void createAdmin(vector<AdminRecord> &admins)
{
    AdminRecord a;
    a.id = readLine("New admin ID: ");
    if (a.id.empty() ||
        any_of(admins.begin(), admins.end(),
               [&a](const AdminRecord &x)
               { return x.id == a.id; }))
    {
        cout << "Admin ID is empty or already in use.\n";
        return;
    }
    a.password = readLine("Password: ");
    if (a.password.empty())
    {
        cout << "Password cannot be empty.\n";
        return;
    }
    a.fullName = readLine("Full name: ");
    a.cnic = normalizeCNIC(readLine("CNIC (13 digits): "));
    if (a.cnic.empty())
    {
        cout << "Invalid CNIC. It must be 13 digits.\n";
        return;
    }
    if (any_of(admins.begin(), admins.end(),
               [&a](const AdminRecord &x)
               { return x.cnic == a.cnic; }))
    {
        cout << "An admin with this CNIC already exists.\n";
        return;
    }
    a.phone = readLine("Phone: ");
    a.address = readLine("Address: ");
    admins.push_back(a);
    saveAdmins(admins);
    cout << "Admin " << a.id << " created.\n";
}

void listAdmins(const vector<AdminRecord> &admins)
{
    for (const AdminRecord &a : admins)
        cout << a.id << " | " << a.fullName << " | " << a.cnic << " | "
             << a.phone << " | " << a.address << '\n';
}

void showCompanyMembers(const string &companyID,
                        const vector<unique_ptr<Account>> &accounts)
{
    static const char *roleNames[] = {"Client", "Employee", "CEO"};
    bool found = false;
    for (const auto &account : accounts)
        if (auto *user = dynamic_cast<const UserAccount *>(account.get()))
            if (user->getCompanyID() == companyID)
            {
                if (!found)
                    cout << "Members:\n";
                cout << "  " << user->getID() << " | " << user->getFullName()
                     << " | " << roleNames[user->getRole()] << '\n';
                found = true;
            }
    if (!found)
        cout << "No employees yet.\n";
}
void assignCEO(CompanyAccount &company, vector<unique_ptr<Account>> &accounts,
               const string &actorID)
{
    UserAccount *currentCEO = nullptr;
    for (const auto &account : accounts)
        if (auto *u = dynamic_cast<UserAccount *>(account.get()))
            if (u->getCompanyID() == company.getID() && u->getRole() == CEO)
                currentCEO = u;

    // With a CEO in place, only that CEO may hand over the role.
    // With none, only the company account itself may name the first one.
    const bool allowed = currentCEO ? (actorID == currentCEO->getID())
                                    : actorID.empty();
    if (!allowed)
    {
        cout << "Only the current CEO can transfer the CEO role.\n";
        return;
    }

    auto *target = dynamic_cast<UserAccount *>(
        findAccount(accounts, readLine("Employee account ID to make CEO: ")));
    if (!target || target->getCompanyID() != company.getID() ||
        target->getRole() == Client)
    {
        cout << "That must be a registered employee of this company.\n";
        return;
    }
    if (currentCEO)
        currentCEO->setRole(Employee);
    target->setRole(CEO);
    saveAccounts(accounts);
    cout << "CEO set to " << target->getID() << ".\n";
}
Card *findCard(vector<Card> &cards, const string &id)
{
    for (Card &card : cards)
        if (card.accountID == id)
            return &card;
    return nullptr;
}

string generateCardNumber(const vector<Card> &cards)
{
    static random_device device;
    static mt19937 generator(device());
    uniform_int_distribution<int> digit(0, 9);
    string number;
    do
    {
        number.clear();
        for (int i = 0; i < 16; ++i)
            number += static_cast<char>('0' + digit(generator));
    } while (any_of(cards.begin(), cards.end(),
                    [&number](const Card &card)
                    { return card.cardNumber == number; }));
    return number;
}

void issueCard(Account &account, vector<Card> &cards)
{
    if (findCard(cards, account.getID()))
    {
        cout << "This account already has a card.\n";
        return;
    }
    string pin;
    do
        pin = readLine("Set a 4-digit card PIN: ");
    while (pin.size() != 4 ||
           !all_of(pin.begin(), pin.end(), [](unsigned char c)
                   { return c >= '0' && c <= '9'; }));
    const string number = generateCardNumber(cards);
    cards.push_back({account.getID(), number, pin});
    saveCards(cards);
    cout << "Card issued. Card number: " << number << " (shown once).\n";
}

bool verifyTransactionCard(Account &account, vector<Card> &cards)
{
    Card *card = findCard(cards, account.getID());
    if (!card)
    {
        cout << "Issue a card before making transactions.\n";
        return false;
    }
    if (card->locked)
    {
        cout << "This card is locked after failed PIN attempts. Contact an employee.\n";
        return false;
    }
    const bool verified = card->verifyPIN(readLine("Enter card PIN: "));
    saveCards(cards);
    if (!verified)
        cout << (card->locked ? "Incorrect PIN. Card locked.\n" : "Incorrect PIN.\n");
    return verified;
}

void displayTransactionHistory(const string &accountID = "")
{
    ifstream file("transactions.txt");
    if (!file)
    {
        cout << "No transaction history is available.\n";
        return;
    }
    string line;
    bool found = false;
    while (getline(file, line))
    {
        istringstream row(line);
        string date, id, amount, type, receiver;
        if (!getline(row, date, ',') || !getline(row, id, ',') ||
            !getline(row, amount, ',') || !getline(row, type, ','))
            continue;
        getline(row, receiver);
        if (!accountID.empty() && id != accountID && receiver != accountID)
            continue;
        cout << date << " | " << id << " | " << amount << " | " << type;
        if (!receiver.empty())
            cout << " -> " << receiver;
        cout << '\n';
        found = true;
    }
    if (!found)
        cout << "No transactions found.\n";
}

// ---------------------------------------------------------------- menus

// One menu for both account kinds. Companies have an extra "Request loan"
// entry at 5, so a user's displayed 5-7 are shifted up by one internally.
void registerUser(vector<unique_ptr<Account>> &accounts,
                  const string &companyID = "", UserRole role = Client)

{
    const string id = readLine("New account ID: ");
    if (id.empty() || findAccount(accounts, id))
    {
        cout << "Account ID is empty or already in use.\n";
        return;
    }
    const string pass = readLine("Password: ");
    const string name = readLine("Full name: ");
    const string address = readLine("Address: ");
    const string phone = readLine("Phone: ");
    const string cnic = normalizeCNIC(readLine("CNIC (13 digits): "));
    if (cnic.empty())
    {
        cout << "Invalid CNIC. It must be 13 digits.\n";
        return;
    }
    if (cnicExists(accounts, cnic))
    {
        cout << "An account with this CNIC already exists.\n";
        return;
    }
    int typeChoice;
    if (!readValue("Account type (1 Bronze, 2 Gold): ", typeChoice) ||
        (typeChoice != 1 && typeChoice != 2))
    {
        cout << "Invalid account type.\n";
        return;
    }
    accounts.push_back(make_unique<UserAccount>(
        id, pass, name, address, phone, cnic, typeChoice == 1 ? Bronze : Gold,
        0, false, false, role, companyID));
    saveAccounts(accounts);
    cout << "Account created and is pending employee approval.\n";
}
void accountMenu(Account &account, bool company, const string &actorID,
                 vector<unique_ptr<Account>> &accounts,
                 vector<Card> &cards, vector<LoanRequest> &loans)
{
    while (true)
    {
        // Recomputed every loop, so a role change takes effect immediately.
        const bool manage = company &&
                            canManageCompany(accounts, account.getID(), actorID);

        cout << "\n1. Account details  2. Deposit  3. Withdraw  4. Transfer\n";
        if (!company)
            cout << "5. Transaction history  6. Issue card  7. Logout\n";
        else if (manage)
            cout << "5. Request loan  6. Transaction history  7. Issue card\n"
                    "8. Open employee account  9. Set CEO  10. Logout\n";
        else
            cout << "6. Transaction history  10. Logout\n";

        int choice;
        if (!readValue("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        const int logoutChoice = company ? 10 : 8;
        if (!company && choice >= 5)
            ++choice;

        // Enforced here too, not just by hiding menu text.
        if (company && !manage &&
            (choice == 5 || choice == 7 || choice == 8 || choice == 9))
        {
            cout << "Only the CEO can do that.\n";
            continue;
        }

        if (choice == 1)
        {
            account.displayInfo();
            if (company)
                showCompanyMembers(account.getID(), accounts);
        }
        else if (choice >= 2 && choice <= 4)
        {
            string destinationID;
            if (choice == 4)
                destinationID = readLine(company ? "Destination user account ID: "
                                                 : "Destination account ID: ");
            double amount;
            if (!readValue("Amount: ", amount))
            {
                cout << "Invalid amount.\n";
                continue;
            }
            if (!verifyTransactionCard(account, cards))
                continue;
            if (choice == 2)
                account.deposit(amount);
            else if (choice == 3)
                account.withdraw(amount);
            else
                account.transfer(findAccount(accounts, destinationID), amount);
            saveAccounts(accounts);
        }
        else if (company && choice == 5)
        {
            double amount;
            if (!readValue("Loan amount: ", amount) || amount <= 0)
            {
                cout << "Enter a positive loan amount.\n";
                continue;
            }
            loans.push_back({account.getID(), amount});
            saveLoans(loans);
            cout << "Loan request submitted.\n";
        }
        else if (choice == 6)
            displayTransactionHistory(account.getID());
        else if (choice == 7)
            issueCard(account, cards);
        else if (company && choice == 8)
            registerUser(accounts, account.getID(), Employee);
        else if (company && choice == 9)
        {
            if (auto *companyAccount = dynamic_cast<CompanyAccount *>(&account))
                assignCEO(*companyAccount, accounts, actorID);
        }
        else if (choice == logoutChoice)
            return;
        else
            cout << "Invalid choice.\n";
    }
}
void registerCompany(vector<unique_ptr<Account>> &accounts)
{
    const string id = readLine("New company account ID: ");
    if (id.empty() || findAccount(accounts, id))
    {
        cout << "Account ID is empty or already in use.\n";
        return;
    }
    const string pass = readLine("Password: ");
    const string name = readLine("Company name: ");
    const string address = readLine("Address: ");
    const string tax = readLine("Tax number: ");
    accounts.push_back(make_unique<CompanyAccount>(id, pass, name, address, tax));
    saveAccounts(accounts);
    cout << "Company account created and is pending employee approval.\n";
}

// Returns 1 (approve), 2 (reject), or 0 for invalid input.
int askApproveOrReject()
{
    int action;
    if (!readValue("1 Approve, 2 Reject: ", action) || (action != 1 && action != 2))
    {
        cout << "Invalid action.\n";
        return 0;
    }
    return action;
}

void employeeMenu(vector<unique_ptr<Account>> &accounts, vector<Card> &cards,
                  vector<LoanRequest> &loans, vector<AdminRecord> &admins)
{
    while (true)
    {
        cout << "\n1. List accounts  2. Approve/reject account  3. Approve/reject loan\n"
             << "4. View transactions  5. Close account  6. Create admin\n"
             << "7. List admins  8. Logout\n";
        int choice;
        if (!readValue("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        if (choice == 1)
        {
            if (accounts.empty())
                cout << "No accounts.\n";
            for (const auto &account : accounts)
                account->displayInfo();
        }
        else if (choice == 2)
        {
            Account *account = findAccount(accounts, readLine("Account ID: "));
            if (!account)
            {
                cout << "Account not found.\n";
                continue;
            }
            const int action = askApproveOrReject();
            if (!action)
                continue;
            account->setApproved(action == 1);
            saveAccounts(accounts);
            cout << (action == 1 ? "Account approved.\n" : "Account rejected.\n");
        }
        else if (choice == 3)
        {
            bool pending = false;
            for (size_t i = 0; i < loans.size(); ++i)
                if (loans[i].status == "Pending")
                {
                    cout << i + 1 << ". Company " << loans[i].companyID << " requests "
                         << loans[i].amount << " PKR\n";
                    pending = true;
                }
            if (!pending)
            {
                cout << "No pending loan requests.\n";
                continue;
            }
            int index;
            if (!readValue("Request number: ", index) || index < 1 ||
                static_cast<size_t>(index) > loans.size() ||
                loans[index - 1].status != "Pending")
            {
                cout << "Invalid or non-pending request.\n";
                continue;
            }
            const int action = askApproveOrReject();
            if (!action)
                continue;
            loans[index - 1].status = action == 1 ? "Approved" : "Rejected";
            saveLoans(loans);
            cout << "Loan request updated.\n";
        }
        else if (choice == 4)
            displayTransactionHistory();
        else if (choice == 5)
        {
            const string id = readLine("Account ID to close: ");
            const auto account = find_if(accounts.begin(), accounts.end(),
                                         [&id](const unique_ptr<Account> &item)
                                         { return item->getID() == id; });
            if (account == accounts.end())
            {
                cout << "Account not found.\n";
                continue;
            }
            accounts.erase(account);
            cards.erase(remove_if(cards.begin(), cards.end(),
                                  [&id](const Card &card)
                                  { return card.accountID == id; }),
                        cards.end());
            saveAccounts(accounts);
            saveCards(cards);
            cout << "Account closed. Transaction history was retained.\n";
        }
        else if (choice == 6)
            createAdmin(admins);
        else if (choice == 7)
            listAdmins(admins);
        else if (choice == 8)
            return;
        else
            cout << "Invalid choice.\n";
    }
}

int main()
{
    vector<unique_ptr<Account>> accounts;
    vector<Card> cards;
    vector<LoanRequest> loans;
    vector<AdminRecord> admins;
    loadUsers(accounts);
    loadCompanies(accounts);
    loadCompanyEmployees(accounts);
    loadCards(cards);
    loadLoans(loans);
    loadAdmins(admins);
    saveAccounts(accounts);
    saveAdmins(admins);
    cerr << "admins loaded: " << admins.size()
         << ", logins: " << loadLogins().size() << '\n';
    while (true)
    {
        cout << "\n------ ABC Bank Management System ------\n"
             << "1. User login  2. Company login  3. Employee login\n"
             << "4. Create user account  5. Create company account  6. Exit\n";
        int choice;
        if (!readValue("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        if (choice == 6)
            break;
        if (choice == 4)
            registerUser(accounts);
        else if (choice == 5)
            registerCompany(accounts);
        else if (choice == 1 || choice == 2)
        {
            const string id = readLine("Account ID: ");
            const string pass = readLine("Password: ");
            Account *account = findAccount(accounts, id);
            if (!authenticate(id, pass, User) || !account || !account->login(id, pass))
            {
                cout << "Login failed. Check credentials, approval, and account status.\n";
                continue;
            }
            if ((account->getType() == Business) != (choice == 2))
            {
                cout << "That is not a " << (choice == 1 ? "user" : "company")
                     << " account.\n";
                continue;
            }
            Account *session = account;
            bool asCompany = (choice == 2);
            const string actorID = (choice == 2) ? "" : account->getID();

            if (choice == 1)
            {
                auto *user = dynamic_cast<UserAccount *>(account);
                if (user && !user->getCompanyID().empty() && user->getRole() != Client)
                {
                    auto *comp = dynamic_cast<CompanyAccount *>(
                        findAccount(accounts, user->getCompanyID()));
                    if (comp && comp->isActive())
                    {
                        int pick;
                        if (readValue("1 Personal account, 2 Company account (" +
                                          comp->getID() + "): ", pick) &&
                            pick == 2)
                        {
                            
                            session = comp;
                            asCompany = true;
                        }
                    }
                }
            }
            accountMenu(*session, asCompany, actorID, accounts, cards, loans);
        }
        else if (choice == 3)
        {
            const string id = readLine("Employee ID: ");
            const string pass = readLine("Password: ");
            if (authenticate(id, pass, Admin))
                employeeMenu(accounts, cards, loans, admins);
            else
                cout << "Employee login failed.\n";
        }
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}