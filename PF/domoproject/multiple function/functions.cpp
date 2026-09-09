#include <iostream>
#include "functions.h"

using namespace std;

void hello()
{
    cout << "Hello!\n";
}

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

bool isEven(int n)
{
    return n % 2 == 0;
}