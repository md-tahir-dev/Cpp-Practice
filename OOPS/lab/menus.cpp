#include "menus.h"

#include <algorithm>
#include <iostream>

#include "bank_ops.h"
#include "cards.h"
#include "storage.h"
#include "utils.h"

// Returns 1 (approve), 2 (reject), or 0 for invalid input.
static int askApproveOrReject()
{
    int action;
    if (!readValue("1 Approve, 2 Reject: ", action) || (action != 1 && action != 2))
    {
        cout << "Invalid action.\n";
        return 0;
    }
    return action;
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