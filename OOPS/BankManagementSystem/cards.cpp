#include "cards.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "storage.h"
#include "utils.h"

Card *findCard(vector<Card> &cards, const string &id)
{
    for (Card &card : cards)
        if (card.accountID == id)
            return &card;
    return nullptr;
}

string generateCardNumber(const vector<Card> &cards)
{
    static random_device device;
    static mt19937 generator(device());
    uniform_int_distribution<int> digit(0, 9);
    string number;
    do
    {
        number.clear();
        for (int i = 0; i < 16; ++i)
            number += static_cast<char>('0' + digit(generator));
    } while (any_of(cards.begin(), cards.end(),
                    [&number](const Card &card)
                    { return card.cardNumber == number; }));
    return number;
}

void issueCard(Account &account, vector<Card> &cards)
{
    if (findCard(cards, account.getID()))
    {
        cout << "This account already has a card.\n";
        return;
    }
    string pin;
    do
        pin = readLine("Set a 4-digit card PIN: ");
    while (pin.size() != 4 ||
           !all_of(pin.begin(), pin.end(), [](unsigned char c)
                   { return c >= '0' && c <= '9'; }));
    const string number = generateCardNumber(cards);
    cards.push_back({account.getID(), number, pin});
    saveCards(cards);
    cout << "Card issued. Card number: " << number << " (shown once).\n";
}

bool verifyTransactionCard(Account &account, vector<Card> &cards)
{
    Card *card = findCard(cards, account.getID());
    if (!card)
    {
        cout << "Issue a card before making transactions.\n";
        return false;
    }
    if (card->locked)
    {
        cout << "This card is locked after failed PIN attempts. Contact an employee.\n";
        return false;
    }
    const bool verified = card->verifyPIN(readLine("Enter card PIN: "));
    saveCards(cards);
    if (!verified)
        cout << (card->locked ? "Incorrect PIN. Card locked.\n" : "Incorrect PIN.\n");
    return verified;
}