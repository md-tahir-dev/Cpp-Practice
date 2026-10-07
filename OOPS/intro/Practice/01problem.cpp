/*Create a C++ class called BankAccount.

Requirements

Private data members:

accountHolder → string
accountNumber → int
balance → double

Your class must have:

A parameterized constructor to initialize all three values.
deposit(double amount)
Amount must be greater than 0.
withdraw(double amount)
Amount must be greater than 0.
Amount cannot be greater than the current balance.
getBalance()
Returns the current balance.
displayAccount()
Displays account holder, account number, and balance.*/

#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int n, double bal)
    {
        accountHolder = name;
        accountNumber = n;
        if (bal >= 0)
        {
            balance = bal;
        }
        else
        {
            cout << "Invalid initial balance. Setting balance to 0." << endl;
            balance = 0;
        }
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << " successfully. New balance: " << balance << endl;
        }
        else
        {
            cout << "Deposit amount must be positive." << endl;
        }
    }
    void withdraw(double amount)
    {
        if (balance >= amount && amount > 0)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " successfully. New balance: " << balance << endl;
        }
        else if (amount <= 0)
        {
            cout << "Withdrawal amount must be positive." << endl;
        }
        else
        {
            cout << "Insufficient balance. Current balance: " << balance << endl;
        }
    }
    double getBalance()
    {
        return balance;
    }
    void displayAccount()
    {
        cout << "Account holder: " << accountHolder << endl;
        cout << "Account number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount ali("Ali", 1001, 5000);
    ali.displayAccount();
    ali.deposit(500);
    ali.withdraw(4000);
    ali.withdraw(1000);
    ali.displayAccount();

    BankAccount ahmad("Ahmad", 1002, 3000);
    ahmad.displayAccount();
    ahmad.deposit(500);
    ahmad.withdraw(4000);
    ahmad.withdraw(1000);
    ahmad.displayAccount();
    return 0;
}