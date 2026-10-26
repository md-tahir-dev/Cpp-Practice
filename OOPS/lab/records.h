#pragma once

#include <string>

#include "common.h"

// Plain data records shared by storage, menus and operations.

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

// login.txt: every user/company (Role::User) and admin (Role::Admin)
struct LoginRecord
{
    string id, password;
    Role role;
};