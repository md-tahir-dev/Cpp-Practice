#include <iostream>
#include <string>

using namespace std;
class BankAccount
{
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double bal)
    {
        accountHolder = name;
        if (bal > 0)
            balance = bal;
        else
            balance = 0; // default to 0 if invalid
    }
    string getName()
    {
        return accountHolder;
    }
    double getBalance()
    {
        return balance;
    }
    void setBalance(double bal)
    {
        if (bal > 0)
            balance = bal;
    }
    void display()
    {
        cout << "Account holder name is: " << getName() << endl;
        cout << "Account holder balance is: " << getBalance() << endl;
    }
};
int main()
{
    BankAccount person1("Muhammad", 70.2);
    // person1.setname("Muhammad");
    // person1.setBalance(70.2);
    // cout << "Account  balance is: " << person1.getBalance() << endl;
    person1.display();
    person1.setBalance(500);
    cout << "\nAfter setting balance to 500:" << endl;
    person1.display();

    person1.setBalance(-200);
    cout << "\nAfter trying to set balance to -200:" << endl;
    person1.display();
    return 0;
}