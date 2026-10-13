#include <iostream>

using namespace std;
void f1(int n)
{
    int b = 2, c = 4, d = 7;
    cout << n << "  " << b << "  " << c << "  " << d << endl;
}
void testing()
{
    int *ptr = nullptr; // Stack
    ptr = new int;      // Heap
    cout << *ptr << endl;
    *ptr = 24;
    cout << *ptr << endl;
    // cout << "Enter an integer: ";
    // cin >> *ptr;
    // cout<<endl;
    // cout << *ptr << endl;
    delete ptr;
    ptr = nullptr;
    // cout<<*ptr<<endl;
}

int main()
{
    // int a=5;
    // int n;
    // cin>>n;
    // int arr[3]={10,15,20};
    // f1(a);
    // f1(40);
    // f1(10);
    for (int i = 0; i < 11; i++)
    {
        testing();
    }
    return 0;
}