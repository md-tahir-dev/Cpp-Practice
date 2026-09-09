/*
Write a program that takes input from user and display it after multiplying it with 5. Repeat the task 
until user input is zero. Do it by using top-testing while loop
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    while (n!=0)
    {
        cout<<"Multiply with 5 is: "<<n*5<<endl;
        cout<<"Enter number: ";
        cin>>n;
    }
    
    return 0;
}
