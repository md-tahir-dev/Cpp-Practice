// C++ Program to illustrate Global Variable
// header files
#include <iostream>
using namespace std;
// global variable
int x = 10; // x is a global variable initialized to 10
void print()
{
    int a = 8;
    cout<<a<<endl;
}

// main function
int main()
{
    cout << x<<endl;
    // cout<<a<<endl;  //we cann't use 
    print();
    return 0;
}