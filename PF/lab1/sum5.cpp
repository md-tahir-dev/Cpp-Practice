/*
Write a program that takes 5 integers from the user and displays their sum on screen. But you can 
only use two variables. (Use While Loop)
*/
#include <iostream>
using namespace std;
int main()
{
    int num,sum=0, count =0;
    while (count<5)
    {
        cout<<"Enter number: ";
        cin>>num;
        sum+=num;
        count++;
    }
    cout<<"Sum is: "<<sum;
    
    return 0;
}