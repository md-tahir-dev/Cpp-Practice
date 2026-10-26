#pragma once

#include <memory>
#include <string>
#include <vector>

#include "account.h"
#include "records.h"

// One menu for both account kinds. Companies have an extra "Request loan"
// entry at 5, so a user's displayed 5-7 are shifted up by one internally.
void accountMenu(Account &account, bool company, const string &actorID,
                 vector<unique_ptr<Account>> &accounts,
                 vector<Card> &cards, vector<LoanRequest> &loans);

void employeeMenu(vector<unique_ptr<Account>> &accounts, vector<Card> &cards,
                  vector<LoanRequest> &loans, vector<AdminRecord> &admins);