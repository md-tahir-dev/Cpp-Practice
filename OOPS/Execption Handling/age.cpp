#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    try
    {
        if (age < 18)
        {
            throw age;
        }

        cout << "You age is eligible: " << age << endl;
    }
    catch (int x)
    {
        cout << "You age isn't eligible: " << x << endl;
    }

    return 0;
}