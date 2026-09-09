/*
Write a C++ program that takes two integers, HIGH and LOW, as input and displays all odd numbers between them.
 If the user enters the values in reverse order, the program should interchange them first.
*/
#include <iostream>
using namespace std;
void find_odd(int first, int second)
{
    while (first<second)
    {
        if(first%2!=0)
        {
            cout<<first<<endl;
        }
        first++;
    }
    
}
int main()
{
    int first, second;
    cout<<"Enter first limit: ";
    cin>>first;
    cout<<"Enter second limit: ";
    cin>>second;
    if(first>second)
    {
        int temp = first;
        first = second;
        second = temp;

    }
    find_odd(first,second);
    return 0;
}