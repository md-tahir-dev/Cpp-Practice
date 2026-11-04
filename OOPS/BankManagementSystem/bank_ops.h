#pragma once

#include <memory>
#include <string>
#include <vector>

#include "account.h"
#include "records.h"

// Lookups and checks
Account *findAccount(vector<unique_ptr<Account>> &accounts, const string &id);
bool canManageCompany(vector<unique_ptr<Account>> &accounts,
                      const string &companyID, const string &actorID);
bool cnicExists(const vector<unique_ptr<Account>> &accounts, const string &cnic);

// Registration
void registerUser(vector<unique_ptr<Account>> &accounts,
                  const string &companyID = "", UserRole role = Client);
void registerCompany(vector<unique_ptr<Account>> &accounts);

// Company management
void showCompanyMembers(const string &companyID,
                        const vector<unique_ptr<Account>> &accounts);
void assignCEO(CompanyAccount &company, vector<unique_ptr<Account>> &accounts,
               const string &actorID);

// Admin management
void createAdmin(vector<AdminRecord> &admins);
void listAdmins(const vector<AdminRecord> &admins);

// Reporting
void displayTransactionHistory(const string &accountID = "");