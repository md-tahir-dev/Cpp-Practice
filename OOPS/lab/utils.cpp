#include "utils.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

string getTodayDate()
{
    char buffer[11];
    time_t now = time(0);
    strftime(buffer, sizeof buffer, "%Y-%m-%d", localtime(&now));
    return buffer;
}

void logTransaction(const string &id, double amount, const string &type,
                    const string &receiver)
{
    ofstream file("transactions.txt", ios::app);
    if (!file)
    {
        cerr << "Error: could not open transactions.txt for writing.\n";
        return;
    }
    file << getTodayDate() << ',' << id << ',' << setprecision(17) << amount
         << ',' << type << ',' << receiver << '\n';
}

string readLine(const string &prompt)
{
    cout << prompt;
    string input;
    if (!getline(cin, input))
        exit(0);
    return input;
}

string normalizeCNIC(const string &input)
{
    string digits;
    for (char c : input)
    {
        if (c >= '0' && c <= '9')
            digits += c;
        else if (c != '-')
            return "";
    }
    return digits.size() == 13 ? digits : "";
}