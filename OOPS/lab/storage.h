#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "account.h"
#include "records.h"

// Accounts
void saveAccounts(const vector<unique_ptr<Account>> &accounts);
void loadUsers(vector<unique_ptr<Account>> &accounts);
void loadCompanies(vector<unique_ptr<Account>> &accounts);
void saveCompanyEmployees(const vector<unique_ptr<Account>> &accounts);
void loadCompanyEmployees(vector<unique_ptr<Account>> &accounts);

// Cards and loans
void saveCards(const vector<Card> &cards);
void loadCards(vector<Card> &cards);
void saveLoans(const vector<LoanRequest> &loans);
void loadLoans(vector<LoanRequest> &loans);

// Logins and admins
vector<LoginRecord> loadLogins();
// Replaces all rows of one role, keeping the other role's rows untouched.
void updateLogins(Role role, const vector<pair<string, string>> &rows);
bool authenticate(const string &id, const string &pass, Role role);
void saveAdmins(const vector<AdminRecord> &admins);
void loadAdmins(vector<AdminRecord> &admins);