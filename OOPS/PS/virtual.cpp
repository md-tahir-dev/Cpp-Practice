
#include <iostream>
using namespace std;

class BankAccount
{
public:
    virtual void calculateInterest()
    {
        cout << "General bank interest" << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void calculateInterest() override
    {
        cout << "Calculating savings account interest" << endl;
    }
};

class BusinessAccount : public BankAccount
{
public:
    void calculateInterest() override
    {
        cout << "Calculating business account interest" << endl;
    }
};

int main()
{
    SavingsAccount savings;
    BusinessAccount business;

    BankAccount* account;

    account = &savings;
    account->calculateInterest();

    account = &business;
    account->calculateInterest();

    return 0;
}
