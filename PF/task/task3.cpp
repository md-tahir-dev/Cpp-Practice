/*
Task 3: Write a program that inputs table number and length of table and then displays the table
using for loop.
*/
#include<iostream>
using namespace std;
int main()
{
    int num, limit, result;
    cout<<"Enter the table number: ";
    cin>>num;
    cout<<"Enter the lenght of the table: ";
    cin>>limit;
    for(int i = 1; i<=limit; i++)
    {
        result = num*i;
        cout<<num<<" X "<<i<<" = "<<result;
        cout<<endl;
    }
    return 0;
}