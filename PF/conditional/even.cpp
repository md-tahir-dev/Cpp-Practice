#include <iostream>
using namespace std;   
int main()
{
    int n; 
    cout << "Enter a number: ";
    cin >> n;
    if (n > 0)
        {cout << n << " is a positive number.\n";
        if (n % 2 == 0)
        {
            cout << n << " is an even number.\n";
        }
        else
        {
            cout << n << " is an odd number.\n";
    }
    }
    else
        {
        cout << n << " is a negative number.\n";
        if (n % 2 == 0)
        {
            cout << n << " is an even number.\n";
        }
        else
        {
            cout << n << " is an odd number.\n";
        }
    }
}