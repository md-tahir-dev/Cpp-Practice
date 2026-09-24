#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    hello();

    cout << "Sum = " << add(5, 3) << endl;

    cout << "Product = " << multiply(5, 3) << endl;

    if (isEven(10))
    {
        cout << "10 is even";
    }

    return 0;
}