#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "common.h"

// Date + transaction log
string getTodayDate();
void logTransaction(const string &id, double amount, const string &type,
                    const string &receiver = "");

// Console input helpers
// Exits cleanly on end-of-input so menus can't loop forever.
string readLine(const string &prompt);

template <typename T>
bool readValue(const string &prompt, T &value)
{
    istringstream stream(readLine(prompt));
    char extra;
    return (stream >> value) && !(stream >> extra);
}

// Returns the 13 digits, or "" if the input isn't a valid CNIC.
string normalizeCNIC(const string &input);