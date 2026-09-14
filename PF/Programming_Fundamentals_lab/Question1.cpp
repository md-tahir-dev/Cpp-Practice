#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    const int size=10;
    int Original[size];
    cout<<"Enter 10 elements: ";
    for (size_t i = 0; i < size; i++)
    {
        cin>>Original[i];
    }
    int Copied1[size];
    for (int i = 0; i < size; i++) 
    {
        Copied1[i] = Original[i];
    }
    cout<<"Printing using loop\n";
    for (int x : Copied1)
    {
        cout<<x<<endl;
    }
    return 0;
}