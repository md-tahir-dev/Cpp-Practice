#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int* p = &x;     // p points to x
    int** pp = &p;   // pp points to p

    cout << *p<<endl;    // prints 10
    cout << **pp;    // prints 10

    return 0;
}