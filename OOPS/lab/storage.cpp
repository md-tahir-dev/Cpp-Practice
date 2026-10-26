#include "storage.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

// ---------------------------------------------------------------- accounts

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

        // Optional field, so old users.txt files still load
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

// ------------------------------------------------------- cards and loans

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

// ------------------------------------------------------ logins and admins

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