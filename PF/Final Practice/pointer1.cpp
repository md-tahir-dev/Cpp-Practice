#include <iostream>

using namespace std;

int main()
{
    int x = 42;      // normal variable
    int* p = &x;     // pointer storing the address of x
    cout << p<<endl;
    cout << *p;
    return 0;
}