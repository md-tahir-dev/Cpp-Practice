#pragma once

#include <iostream>
#include <string>

#include "common.h"

// ---------------------------------------------------------------- Account

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
    bool canDebit(double amount, const string &action);

public:
    Account(const string &id, const string &pass, double initialBalance,
            AccountType accountType, bool approved, bool frozen);

    virtual ~Account() = default;
    virtual void displayInfo() const = 0;
    virtual void write(ostream &out) const = 0;

    const string &getPassword() const { return password; }
    bool login(const string &id, const string &pass) const
    {
        return accountID == id && password == pass && active();
    }
    const string &getID() const { return accountID; }
    bool isActive() const { return active(); }
    AccountType getType() const { return type; }
    void setApproved(bool value) { isApproved = value; }

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Account *to, double amount);
};

// ------------------------------------------------------------ UserAccount

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
                const string &company = "");

    const string &getFullName() const { return fullName; }
    const string &getCNIC() const { return cnic; }
    const string &getCompanyID() const { return companyID; }
    UserRole getRole() const { return role; }
    void setRole(UserRole newRole) { role = newRole; }
    void setCompanyID(const string &id) { companyID = id; }

    void displayInfo() const override;
    void write(ostream &out) const override;
};

// ---------------------------------------------------------- CompanyAccount

class CompanyAccount : public Account
{
    string companyName, companyAddress, taxNumber;

    bool canSendTo(const Account *to) const override;

public:
    CompanyAccount(const string &id, const string &pass, const string &name,
                   const string &addr, const string &tax,
                   double initialBalance = 0, bool approved = false,
                   bool frozen = false);

    void displayInfo() const override;
    void write(ostream &out) const override;
};