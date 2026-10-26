#include "bank_ops.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "storage.h"
#include "utils.h"

// ----------------------------------------------------- lookups and checks

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

bool cnicExists(const vector<unique_ptr<Account>> &accounts, const string &cnic)
{
    for (const auto &account : accounts)
        if (auto *user = dynamic_cast<const UserAccount *>(account.get()))
            if (user->getCNIC() == cnic)
                return true;
    return false;
}

// ------------------------------------------------------------ registration

void registerUser(vector<unique_ptr<Account>> &accounts,
                  const string &companyID, UserRole role)
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

// ------------------------------------------------------ company management

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

// -------------------------------------------------------- admin management

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

// --------------------------------------------------------------- reporting

void displayTransactionHistory(const string &accountID)
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