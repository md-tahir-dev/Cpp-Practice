#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int& ref = x;   // ref is another name for x
    cout<<ref<<endl;    //prints 10
    ref = 20;       // changes x
    cout << x;      // prints 20
    return 0;
}