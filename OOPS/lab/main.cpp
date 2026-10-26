#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "account.h"
#include "bank_ops.h"
#include "menus.h"
#include "records.h"
#include "storage.h"
#include "utils.h"

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