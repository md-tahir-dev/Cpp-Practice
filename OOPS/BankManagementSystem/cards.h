#pragma once

#include <string>
#include <vector>

#include "account.h"
#include "records.h"

Card *findCard(vector<Card> &cards, const string &id);
string generateCardNumber(const vector<Card> &cards);
void issueCard(Account &account, vector<Card> &cards);
bool verifyTransactionCard(Account &account, vector<Card> &cards);