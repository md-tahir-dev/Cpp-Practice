#include <algorithm>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum AccountType
{
    Bronze,
    Gold,
    Business
};

string getTodayDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[11];
    sprintf(buffer, "%04d-%02d-%02d", 1900 + localTime->tm_year,
            1 + localTime->tm_mon, localTime->tm_mday);
    return string(buffer);
}

class Transaction
{
private:
    string date;
    string accountID;
    double amount;
    string type;
    string receiverID;

public:
    Transaction(const string &transactionDate, const string &id, double value,
                const string &transactionType, const string &receiver = "")
        : date(transactionDate), accountID(id), amount(value),
          type(transactionType), receiverID(receiver) {}

    bool logTransaction() const
    {
        ofstream file("transactions.txt", ios::app);
        if (!file)
        {
            cerr << "Error: could not open transactions.txt for writing.\n";
            return false;
        }
        file << date << "," << accountID << "," << setprecision(17) << amount
             << "," << type << "," << receiverID << '\n';
        return static_cast<bool>(file);
    }
};

class Account
{
protected:
    string accountID;
    string password;
    double balance;
    double dailyLimit;
    bool isApproved;
    bool isFrozen;
    AccountType type;
    double dailyWithdrawn;
    string lastTransactionDate;

public:
    Account(const string &id, const string &pass, double initialBalance,
            AccountType accountType, bool approved = false, bool frozen = false)
        : accountID(id), password(pass), balance(initialBalance), dailyLimit(0),
          isApproved(approved), isFrozen(frozen), type(accountType),
          dailyWithdrawn(0), lastTransactionDate("")
    {
        switch (type)
        {
        case Bronze:
            dailyLimit = 100000;
            break;
        case Gold:
            dailyLimit = 500000;
            break;
        case Business:
            dailyLimit = 20000000;
            break;
        }
    }

    virtual ~Account() = default;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void transfer(Account *to, double amount) = 0;
    virtual void displayInfo() const = 0;

    bool login(const string &id, const string &pass) const
    {
        return accountID == id && password == pass && isApproved && !isFrozen;
    }
    bool canWithdraw(double amount)
    {
        const string today = getTodayDate();
        if (today != lastTransactionDate)
        {
            dailyWithdrawn = 0;
            lastTransactionDate = today;
        }
        return dailyWithdrawn + amount <= dailyLimit;
    }
    void recordWithdrawal(double amount) { dailyWithdrawn += amount; }
    const string &getID() const { return accountID; }
    const string &getPassword() const { return password; }
    double getBalance() const { return balance; }
    AccountType getType() const { return type; }
    bool getApprovalStatus() const { return isApproved; }
    bool getFrozenStatus() const { return isFrozen; }
    void setApproved(bool value) { isApproved = value; }
    void setFrozen(bool value) { isFrozen = value; }
    void setBalance(double value) { balance = value; }
};

class UserAccount : public Account
{
private:
    string fullName;
    string address;
    string phone;
    string cnic;

public:
    UserAccount(const string &id, const string &pass, const string &name,
                const string &addr, const string &phoneNumber,
                const string &cnicNumber, AccountType accountType,
                double initialBalance = 0, bool approved = false,
                bool frozen = false)
        : Account(id, pass, initialBalance, accountType, approved, frozen),
          fullName(name), address(addr), phone(phoneNumber), cnic(cnicNumber) {}

    const string &getName() const { return fullName; }
    const string &getAddress() const { return address; }
    const string &getPhone() const { return phone; }
    const string &getCNIC() const { return cnic; }

    void deposit(double amount) override
    {
        if (amount <= 0 || !isApproved || isFrozen)
        {
            cout << "Deposit denied. Check the amount and account status.\n";
            return;
        }
        balance += amount;
        Transaction(getTodayDate(), accountID, amount, "Deposit").logTransaction();
        cout << "Deposited " << amount << " PKR. New balance: " << balance << '\n';
    }

    void withdraw(double amount) override
    {
        if (amount <= 0 || !isApproved || isFrozen)
        {
            cout << "Withdrawal denied. Check the amount and account status.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Withdrawal denied. Insufficient balance.\n";
            return;
        }
        if (!canWithdraw(amount))
        {
            cout << "Withdrawal denied. Daily limit exceeded.\n";
            return;
        }
        balance -= amount;
        recordWithdrawal(amount);
        Transaction(getTodayDate(), accountID, amount, "Withdrawal").logTransaction();
        cout << "Withdrew " << amount << " PKR. New balance: " << balance << '\n';
    }

    void transfer(Account *to, double amount) override
    {
        if (to == nullptr || to == this || amount <= 0 ||
            !isApproved || isFrozen || !to->getApprovalStatus() || to->getFrozenStatus())
        {
            cout << "Transfer denied. Check the destination, amount, and account status.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Transfer denied. Insufficient balance.\n";
            return;
        }
        if (!canWithdraw(amount))
        {
            cout << "Transfer denied. Daily limit exceeded.\n";
            return;
        }
        balance -= amount;
        to->setBalance(to->getBalance() + amount);
        recordWithdrawal(amount);
        Transaction(getTodayDate(), accountID, amount, "Transfer", to->getID()).logTransaction();
        cout << "Transferred " << amount << " PKR to " << to->getID() << ".\n";
    }

    void displayInfo() const override
    {
        cout << "User: " << fullName << " | ID: " << accountID
             << " | Type: " << (type == Bronze ? "Bronze" : "Gold")
             << " | Balance: " << balance
             << " | Status: " << (isApproved ? "Approved" : "Pending")
             << (isFrozen ? " (Frozen)" : "") << '\n';
    }
};

class CompanyAccount : public Account
{
private:
    string companyName;
    string companyAddress;
    string taxNumber;

public:
    CompanyAccount(const string &id, const string &pass, const string &name,
                   const string &addr, const string &tax,
                   double initialBalance = 0, bool approved = false,
                   bool frozen = false)
        : Account(id, pass, initialBalance, Business, approved, frozen),
          companyName(name), companyAddress(addr), taxNumber(tax) {}

    const string &getName() const { return companyName; }
    const string &getAddress() const { return companyAddress; }
    const string &getTaxNumber() const { return taxNumber; }

    void deposit(double amount) override
    {
        if (amount <= 0 || !isApproved || isFrozen)
        {
            cout << "Deposit denied. Check the amount and account status.\n";
            return;
        }
        balance += amount;
        Transaction(getTodayDate(), accountID, amount, "Deposit").logTransaction();
        cout << "Deposited " << amount << " PKR. New balance: " << balance << '\n';
    }

    void withdraw(double amount) override
    {
        if (amount <= 0 || !isApproved || isFrozen)
        {
            cout << "Withdrawal denied. Check the amount and account status.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Withdrawal denied. Insufficient balance.\n";
            return;
        }
        if (!canWithdraw(amount))
        {
            cout << "Withdrawal denied. Daily limit exceeded.\n";
            return;
        }
        balance -= amount;
        recordWithdrawal(amount);
        Transaction(getTodayDate(), accountID, amount, "Withdrawal").logTransaction();
        cout << "Withdrew " << amount << " PKR. New balance: " << balance << '\n';
    }

    void transfer(Account *to, double amount) override
    {
        if (to == nullptr || to == this || dynamic_cast<UserAccount *>(to) == nullptr ||
            amount <= 0 || !isApproved || isFrozen ||
            !to->getApprovalStatus() || to->getFrozenStatus())
        {
            cout << "Transfer denied. Companies can transfer only to active user accounts.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Transfer denied. Insufficient balance.\n";
            return;
        }
        if (!canWithdraw(amount))
        {
            cout << "Transfer denied. Daily limit exceeded.\n";
            return;
        }
        balance -= amount;
        to->setBalance(to->getBalance() + amount);
        recordWithdrawal(amount);
        Transaction(getTodayDate(), accountID, amount, "Transfer", to->getID()).logTransaction();
        cout << "Transferred " << amount << " PKR to " << to->getID() << ".\n";
    }

    void displayInfo() const override
    {
        cout << "Company: " << companyName << " | ID: " << accountID
             << " | Address: " << companyAddress << " | Tax: " << taxNumber
             << " | Balance: " << balance
             << " | Status: " << (isApproved ? "Approved" : "Pending")
             << (isFrozen ? " (Frozen)" : "") << '\n';
    }
};

class Card
{
private:
    string accountID;
    string cardNumber;
    string pin;
    int failedAttempts;
    bool locked;

public:
    Card(const string &id, const string &number, const string &pinCode,
         int failures = 0, bool isLocked = false)
        : accountID(id), cardNumber(number), pin(pinCode),
          failedAttempts(failures), locked(isLocked) {}

    const string &getAccountID() const { return accountID; }
    const string &getCardNumber() const { return cardNumber; }
    const string &getPIN() const { return pin; }
    int getFailedAttempts() const { return failedAttempts; }
    bool isLocked() const { return locked; }

    bool verifyPIN(const string &enteredPIN)
    {
        if (locked)
            return false;
        if (enteredPIN == pin)
        {
            failedAttempts = 0;
            return true;
        }
        if (++failedAttempts >= 3)
            locked = true;
        return false;
    }
};

class LoanRequest
{
private:
    string companyID;
    double amount;
    string status;

public:
    LoanRequest(const string &id, double value, const string &state = "Pending")
        : companyID(id), amount(value), status(state) {}
    const string &getCompanyID() const { return companyID; }
    double getAmount() const { return amount; }
    const string &getStatus() const { return status; }
    void approveRequest() { status = "Approved"; }
    void rejectRequest() { status = "Rejected"; }
};

class BankingEmployee
{
private:
    string empID;
    string password;

public:
    BankingEmployee(const string &id, const string &pass) : empID(id), password(pass) {}

    bool login(const string &enteredID, const string &enteredPass) const
    {
        ifstream file("admin.txt");
        if (!file)
        {
            cerr << "Error: admin.txt not found.\n";
            return false;
        }
        string id, pass;
        while (file >> id >> pass)
            if (id == enteredID && pass == enteredPass)
                return true;
        return false;
    }
};

void saveUserToFile(const UserAccount &user)
{
    ofstream file("users.txt", ios::app);
    if (!file)
    {
        cerr << "Error: could not open users.txt for writing.\n";
        return;
    }
    file << quoted(user.getID()) << ' ' << quoted(user.getPassword()) << ' '
         << setprecision(17) << user.getBalance() << ' '
         << static_cast<int>(user.getType()) << ' '
         << user.getApprovalStatus() << ' ' << user.getFrozenStatus() << ' '
         << quoted(user.getName()) << ' ' << quoted(user.getAddress()) << ' '
         << quoted(user.getPhone()) << ' ' << quoted(user.getCNIC()) << '\n';
}

void saveCompanyToFile(const CompanyAccount &company)
{
    ofstream file("companies.txt", ios::app);
    if (!file)
    {
        cerr << "Error: could not open companies.txt for writing.\n";
        return;
    }
    file << quoted(company.getID()) << ' ' << quoted(company.getPassword()) << ' '
         << setprecision(17) << company.getBalance() << ' '
         << company.getApprovalStatus() << ' ' << company.getFrozenStatus() << ' '
         << quoted(company.getName()) << ' ' << quoted(company.getAddress()) << ' '
         << quoted(company.getTaxNumber()) << '\n';
}

bool saveAccounts(const vector<unique_ptr<Account>> &accounts)
{
    ofstream users("users.txt", ios::trunc);
    ofstream companies("companies.txt", ios::trunc);
    if (!users || !companies)
    {
        cerr << "Error: could not save account files.\n";
        return false;
    }
    for (const auto &account : accounts)
    {
        if (const UserAccount *user = dynamic_cast<const UserAccount *>(account.get()))
        {
            users << quoted(user->getID()) << ' ' << quoted(user->getPassword()) << ' '
                  << setprecision(17) << user->getBalance() << ' '
                  << static_cast<int>(user->getType()) << ' '
                  << user->getApprovalStatus() << ' ' << user->getFrozenStatus() << ' '
                  << quoted(user->getName()) << ' ' << quoted(user->getAddress()) << ' '
                  << quoted(user->getPhone()) << ' ' << quoted(user->getCNIC()) << '\n';
        }
        else if (const CompanyAccount *company =
                     dynamic_cast<const CompanyAccount *>(account.get()))
        {
            companies << quoted(company->getID()) << ' '
                      << quoted(company->getPassword()) << ' '
                      << setprecision(17) << company->getBalance() << ' '
                      << company->getApprovalStatus() << ' '
                      << company->getFrozenStatus() << ' '
                      << quoted(company->getName()) << ' '
                      << quoted(company->getAddress()) << ' '
                      << quoted(company->getTaxNumber()) << '\n';
        }
    }
    if (!users || !companies)
    {
        cerr << "Error: failed while saving account files.\n";
        return false;
    }
    return true;
}

void loadUsersFromFile(vector<unique_ptr<Account>> &accounts)
{
    ifstream file("users.txt");
    if (!file)
        return;
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, pass, name, address, phone, cnic;
        double balance;
        int accountType, approved, frozen;
        if (!(row >> quoted(id) >> quoted(pass) >> balance >> accountType
              >> approved >> frozen >> quoted(name) >> quoted(address)
              >> quoted(phone) >> quoted(cnic)))
        {
            vector<string> legacyFields;
            istringstream legacyRow(line);
            string field;
            while (getline(legacyRow, field, ','))
                legacyFields.push_back(field);

            if (legacyFields.size() == 2 || legacyFields.size() == 7)
            {
                istringstream balanceField(legacyFields[1]);
                char extra;
                if (!(balanceField >> balance) || (balanceField >> extra) || balance < 0)
                {
                    cerr << "Warning: skipping an invalid users.txt record.\n";
                    continue;
                }
                accountType = Bronze;
                name = address = phone = cnic = "";
                if (legacyFields.size() == 7)
                {
                    istringstream typeField(legacyFields[2]);
                    if (!(typeField >> accountType) ||
                        (accountType != Bronze && accountType != Gold))
                    {
                        cerr << "Warning: skipping an invalid users.txt account type.\n";
                        continue;
                    }
                    name = legacyFields[3];
                    address = legacyFields[4];
                    phone = legacyFields[5];
                    cnic = legacyFields[6];
                }
                accounts.push_back(unique_ptr<Account>(new UserAccount(
                    legacyFields[0], "", name, address, phone, cnic,
                    static_cast<AccountType>(accountType), balance)));
                continue;
            }
            cerr << "Warning: skipping an invalid users.txt record.\n";
            continue;
        }
        if ((accountType != Bronze && accountType != Gold) || balance < 0)
        {
            cerr << "Warning: skipping an invalid users.txt account.\n";
            continue;
        }
        accounts.push_back(unique_ptr<Account>(new UserAccount(
            id, pass, name, address, phone, cnic, static_cast<AccountType>(accountType),
            balance, approved != 0, frozen != 0)));
    }
}

void loadCompaniesFromFile(vector<unique_ptr<Account>> &accounts)
{
    ifstream file("companies.txt");
    if (!file)
        return;
    string line;
    while (getline(file, line))
    {
        istringstream row(line);
        string id, pass, name, address, tax;
        double balance;
        int approved, frozen;
        if (!(row >> quoted(id) >> quoted(pass) >> balance >> approved >> frozen
              >> quoted(name) >> quoted(address) >> quoted(tax)) || balance < 0)
        {
            cerr << "Warning: skipping an invalid companies.txt record.\n";
            continue;
        }
        accounts.push_back(unique_ptr<Account>(new CompanyAccount(
            id, pass, name, address, tax, balance, approved != 0, frozen != 0)));
    }
}

void saveCards(const vector<Card> &cards)
{
    ofstream file("cards.txt", ios::trunc);
    if (!file)
    {
        cerr << "Error: could not open cards.txt for writing.\n";
        return;
    }
    for (const Card &card : cards)
        file << quoted(card.getAccountID()) << ' ' << quoted(card.getCardNumber())
             << ' ' << quoted(card.getPIN()) << ' ' << card.getFailedAttempts()
             << ' ' << card.isLocked() << '\n';
}

void loadCards(vector<Card> &cards)
{
    ifstream file("cards.txt");
    if (!file)
        return;
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
        cards.push_back(Card(id, number, pin, failures, locked != 0));
    }
}

void saveLoans(const vector<LoanRequest> &loans)
{
    ofstream file("loans.txt", ios::trunc);
    if (!file)
    {
        cerr << "Error: could not open loans.txt for writing.\n";
        return;
    }
    for (const LoanRequest &loan : loans)
        file << quoted(loan.getCompanyID()) << ' ' << setprecision(17)
             << loan.getAmount() << ' ' << quoted(loan.getStatus()) << '\n';
}

void loadLoans(vector<LoanRequest> &loans)
{
    ifstream file("loans.txt");
    if (!file)
        return;
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
        loans.push_back(LoanRequest(id, amount, status));
    }
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
    } while (any_of(cards.begin(), cards.end(), [&number](const Card &card)
                    { return card.getCardNumber() == number; }));
    return number;
}

bool accountIDExists(const vector<unique_ptr<Account>> &accounts, const string &id)
{
    return any_of(accounts.begin(), accounts.end(), [&id](const unique_ptr<Account> &account)
                  { return account->getID() == id; });
}

Account *findAccount(vector<unique_ptr<Account>> &accounts, const string &id)
{
    for (const auto &account : accounts)
        if (account->getID() == id)
            return account.get();
    return nullptr;
}

Card *findCard(vector<Card> &cards, const string &id)
{
    for (Card &card : cards)
        if (card.getAccountID() == id)
            return &card;
    return nullptr;
}

void issueCard(Account &account, vector<Card> &cards)
{
    if (findCard(cards, account.getID()) != nullptr)
    {
        cout << "This account already has a card.\n";
        return;
    }
    string pin;
    do
    {
        cout << "Set a 4-digit card PIN: ";
        getline(cin, pin);
    } while (pin.size() != 4 || !all_of(pin.begin(), pin.end(), [](unsigned char c)
                                         { return c >= '0' && c <= '9'; }));
    const string number = generateCardNumber(cards);
    cards.push_back(Card(account.getID(), number, pin));
    saveCards(cards);
    cout << "Card issued. Card number: " << number << " (shown once).\n";
}

bool verifyTransactionCard(Account &account, vector<Card> &cards)
{
    Card *card = findCard(cards, account.getID());
    if (card == nullptr)
    {
        cout << "Issue a card before making transactions.\n";
        return false;
    }
    if (card->isLocked())
    {
        cout << "This card is locked after failed PIN attempts. Contact an employee.\n";
        return false;
    }
    cout << "Enter card PIN: ";
    string pin;
    getline(cin, pin);
    const bool verified = card->verifyPIN(pin);
    saveCards(cards);
    if (!verified)
        cout << (card->isLocked() ? "Incorrect PIN. Card locked.\n" : "Incorrect PIN.\n");
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

bool readDouble(const string &prompt, double &value)
{
    cout << prompt;
    string input;
    getline(cin, input);
    istringstream stream(input);
    char extra;
    return (stream >> value) && !(stream >> extra);
}

bool readChoice(const string &prompt, int &choice)
{
    cout << prompt;
    string input;
    getline(cin, input);
    istringstream stream(input);
    char extra;
    return (stream >> choice) && !(stream >> extra);
}

void persistAfterTransaction(const vector<unique_ptr<Account>> &accounts)
{
    saveAccounts(accounts);
}

void userMenu(Account &account, vector<unique_ptr<Account>> &accounts,
              vector<Card> &cards)
{
    while (true)
    {
        cout << "\n1. Account details  2. Deposit  3. Withdraw  4. Transfer\n"
             << "5. Transaction history  6. Issue card  7. Logout\n";
        int choice;
        if (!readChoice("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        if (choice == 1)
            account.displayInfo();
        else if (choice == 2 || choice == 3)
        {
            double amount;
            if (!readDouble("Amount: ", amount))
            {
                cout << "Invalid amount.\n";
                continue;
            }
            if (verifyTransactionCard(account, cards))
            {
                if (choice == 2)
                    account.deposit(amount);
                else
                    account.withdraw(amount);
                persistAfterTransaction(accounts);
            }
        }
        else if (choice == 4)
        {
            string destinationID;
            double amount;
            cout << "Destination account ID: ";
            getline(cin, destinationID);
            if (!readDouble("Amount: ", amount))
            {
                cout << "Invalid amount.\n";
                continue;
            }
            if (verifyTransactionCard(account, cards))
            {
                account.transfer(findAccount(accounts, destinationID), amount);
                persistAfterTransaction(accounts);
            }
        }
        else if (choice == 5)
            displayTransactionHistory(account.getID());
        else if (choice == 6)
            issueCard(account, cards);
        else if (choice == 7)
            return;
        else
            cout << "Invalid choice.\n";
    }
}

void companyMenu(CompanyAccount &company, vector<unique_ptr<Account>> &accounts,
                 vector<Card> &cards, vector<LoanRequest> &loans)
{
    while (true)
    {
        cout << "\n1. Account details  2. Deposit  3. Withdraw  4. Transfer\n"
             << "5. Request loan  6. Transaction history  7. Issue card  8. Logout\n";
        int choice;
        if (!readChoice("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        if (choice == 1)
            company.displayInfo();
        else if (choice == 2 || choice == 3)
        {
            double amount;
            if (!readDouble("Amount: ", amount))
            {
                cout << "Invalid amount.\n";
                continue;
            }
            if (verifyTransactionCard(company, cards))
            {
                if (choice == 2)
                    company.deposit(amount);
                else
                    company.withdraw(amount);
                persistAfterTransaction(accounts);
            }
        }
        else if (choice == 4)
        {
            string destinationID;
            double amount;
            cout << "Destination user account ID: ";
            getline(cin, destinationID);
            if (!readDouble("Amount: ", amount))
            {
                cout << "Invalid amount.\n";
                continue;
            }
            if (verifyTransactionCard(company, cards))
            {
                company.transfer(findAccount(accounts, destinationID), amount);
                persistAfterTransaction(accounts);
            }
        }
        else if (choice == 5)
        {
            double amount;
            if (!readDouble("Loan amount: ", amount) || amount <= 0)
            {
                cout << "Enter a positive loan amount.\n";
                continue;
            }
            loans.push_back(LoanRequest(company.getID(), amount));
            saveLoans(loans);
            cout << "Loan request submitted.\n";
        }
        else if (choice == 6)
            displayTransactionHistory(company.getID());
        else if (choice == 7)
            issueCard(company, cards);
        else if (choice == 8)
            return;
        else
            cout << "Invalid choice.\n";
    }
}

void registerUser(vector<unique_ptr<Account>> &accounts)
{
    string id, pass, name, address, phone, cnic;
    cout << "New account ID: ";
    getline(cin, id);
    if (id.empty() || accountIDExists(accounts, id))
    {
        cout << "Account ID is empty or already in use.\n";
        return;
    }
    cout << "Password: ";
    getline(cin, pass);
    cout << "Full name: ";
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "CNIC: ";
    getline(cin, cnic);
    int typeChoice;
    if (!readChoice("Account type (1 Bronze, 2 Gold): ", typeChoice) ||
        (typeChoice != 1 && typeChoice != 2))
    {
        cout << "Invalid account type.\n";
        return;
    }
    AccountType type = typeChoice == 1 ? Bronze : Gold;
    accounts.push_back(unique_ptr<Account>(
        new UserAccount(id, pass, name, address, phone, cnic, type)));
    saveAccounts(accounts);
    cout << "Account created and is pending employee approval.\n";
}

void registerCompany(vector<unique_ptr<Account>> &accounts)
{
    string id, pass, name, address, tax;
    cout << "New company account ID: ";
    getline(cin, id);
    if (id.empty() || accountIDExists(accounts, id))
    {
        cout << "Account ID is empty or already in use.\n";
        return;
    }
    cout << "Password: ";
    getline(cin, pass);
    cout << "Company name: ";
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    cout << "Tax number: ";
    getline(cin, tax);
    accounts.push_back(unique_ptr<Account>(
        new CompanyAccount(id, pass, name, address, tax)));
    saveAccounts(accounts);
    cout << "Company account created and is pending employee approval.\n";
}

void employeeMenu(BankingEmployee &, vector<unique_ptr<Account>> &accounts,
                  vector<Card> &cards, vector<LoanRequest> &loans)
{
    while (true)
    {
        cout << "\n1. List accounts  2. Approve/reject account  3. Approve/reject loan\n"
             << "4. View transactions  5. Close account  6. Logout\n";
        int choice;
        if (!readChoice("Choice: ", choice))
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
            string id;
            int action;
            cout << "Account ID: ";
            getline(cin, id);
            Account *account = findAccount(accounts, id);
            if (account == nullptr)
            {
                cout << "Account not found.\n";
                continue;
            }
            if (!readChoice("1 Approve, 2 Reject: ", action) ||
                (action != 1 && action != 2))
            {
                cout << "Invalid action.\n";
                continue;
            }
            account->setApproved(action == 1);
            saveAccounts(accounts);
            cout << (action == 1 ? "Account approved.\n" : "Account rejected.\n");
        }
        else if (choice == 3)
        {
            bool pending = false;
            for (size_t i = 0; i < loans.size(); ++i)
                if (loans[i].getStatus() == "Pending")
                {
                    cout << i + 1 << ". Company " << loans[i].getCompanyID()
                         << " requests " << loans[i].getAmount() << " PKR\n";
                    pending = true;
                }
            if (!pending)
            {
                cout << "No pending loan requests.\n";
                continue;
            }
            int index, action;
            if (!readChoice("Request number: ", index) || index < 1 ||
                static_cast<size_t>(index) > loans.size() ||
                loans[static_cast<size_t>(index - 1)].getStatus() != "Pending")
            {
                cout << "Invalid or non-pending request.\n";
                continue;
            }
            if (!readChoice("1 Approve, 2 Reject: ", action) ||
                (action != 1 && action != 2))
            {
                cout << "Invalid action.\n";
                continue;
            }
            if (action == 1)
                loans[static_cast<size_t>(index - 1)].approveRequest();
            else
                loans[static_cast<size_t>(index - 1)].rejectRequest();
            saveLoans(loans);
            cout << "Loan request updated.\n";
        }
        else if (choice == 4)
            displayTransactionHistory();
        else if (choice == 5)
        {
            string id;
            cout << "Account ID to close: ";
            getline(cin, id);
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
                                  { return card.getAccountID() == id; }),
                        cards.end());
            saveAccounts(accounts);
            saveCards(cards);
            cout << "Account closed. Transaction history was retained.\n";
        }
        else if (choice == 6)
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
    loadUsersFromFile(accounts);
    loadCompaniesFromFile(accounts);
    loadCards(cards);
    loadLoans(loans);

    while (true)
    {
        cout << "\n=== ABC Bank Management System ===\n"
             << "1. User login  2. Company login  3. Employee login\n"
             << "4. Create user account  5. Create company account  6. Exit\n";
        int choice;
        if (!readChoice("Choice: ", choice))
        {
            cout << "Enter a valid menu number.\n";
            continue;
        }
        if (choice == 6)
            break;
        if (choice == 4)
        {
            registerUser(accounts);
            continue;
        }
        if (choice == 5)
        {
            registerCompany(accounts);
            continue;
        }
        if (choice == 1 || choice == 2)
        {
            string id, pass;
            cout << "Account ID: ";
            getline(cin, id);
            cout << "Password: ";
            getline(cin, pass);
            Account *account = findAccount(accounts, id);
            if (account == nullptr || !account->login(id, pass))
            {
                cout << "Login failed. Check credentials, approval, and account status.\n";
                continue;
            }
            if (choice == 1)
            {
                UserAccount *user = dynamic_cast<UserAccount *>(account);
                if (user == nullptr)
                {
                    cout << "That is not a user account.\n";
                    continue;
                }
                userMenu(*user, accounts, cards);
            }
            else
            {
                CompanyAccount *company = dynamic_cast<CompanyAccount *>(account);
                if (company == nullptr)
                {
                    cout << "That is not a company account.\n";
                    continue;
                }
                companyMenu(*company, accounts, cards, loans);
            }
        }
        else if (choice == 3)
        {
            string id, pass;
            cout << "Employee ID: ";
            getline(cin, id);
            cout << "Password: ";
            getline(cin, pass);
            BankingEmployee employee(id, pass);
            if (employee.login(id, pass))
                employeeMenu(employee, accounts, cards, loans);
            else
                cout << "Employee login failed.\n";
        }
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}
