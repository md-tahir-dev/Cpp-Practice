#include "account.h"

#include <iomanip>

#include "utils.h"

// ---------------------------------------------------------------- Account

Account::Account(const string &id, const string &pass, double initialBalance,
                 AccountType accountType, bool approved, bool frozen)
    : accountID(id), password(pass), balance(initialBalance),
      isApproved(approved), isFrozen(frozen), type(accountType)
{
    static const double limits[] = {100000, 500000, 20000000};
    dailyLimit = limits[type];
}

bool Account::canDebit(double amount, const string &action)
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

void Account::deposit(double amount)
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

void Account::withdraw(double amount)
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

void Account::transfer(Account *to, double amount)
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

// ------------------------------------------------------------ UserAccount

UserAccount::UserAccount(const string &id, const string &pass,
                         const string &name, const string &addr,
                         const string &phoneNumber, const string &cnicNumber,
                         AccountType accountType, double initialBalance,
                         bool approved, bool frozen, UserRole userRole,
                         const string &company)
    : Account(id, pass, initialBalance, accountType, approved, frozen),
      fullName(name), address(addr), phone(phoneNumber), cnic(cnicNumber),
      companyID(company), role(userRole) {}

void UserAccount::displayInfo() const
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

void UserAccount::write(ostream &out) const
{
    out << quoted(accountID) << ' ' << quoted(password) << ' '
        << setprecision(17) << balance << ' ' << type << ' ' << isApproved
        << ' ' << isFrozen << ' ' << quoted(fullName) << ' ' << quoted(address)
        << ' ' << quoted(phone) << ' ' << quoted(cnic) << ' ' << role << '\n';
}

// ---------------------------------------------------------- CompanyAccount

CompanyAccount::CompanyAccount(const string &id, const string &pass,
                               const string &name, const string &addr,
                               const string &tax, double initialBalance,
                               bool approved, bool frozen)
    : Account(id, pass, initialBalance, Business, approved, frozen),
      companyName(name), companyAddress(addr), taxNumber(tax) {}

bool CompanyAccount::canSendTo(const Account *to) const
{
    return dynamic_cast<const UserAccount *>(to) != nullptr;
}

void CompanyAccount::displayInfo() const
{
    cout << "Company: " << companyName << " | ID: " << accountID
         << " | Address: " << companyAddress << " | Tax: " << taxNumber
         << " | Balance: " << balance
         << " | Status: " << (isApproved ? "Approved" : "Pending")
         << (isFrozen ? " (Frozen)" : "") << '\n';
}

void CompanyAccount::write(ostream &out) const
{
    out << quoted(accountID) << ' ' << quoted(password) << ' '
        << setprecision(17) << balance << ' ' << isApproved << ' '
        << isFrozen << ' ' << quoted(companyName) << ' '
        << quoted(companyAddress) << ' ' << quoted(taxNumber) << '\n';
}