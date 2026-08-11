#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Largest digit is: " << largestDigit(n);

    return 0;
}