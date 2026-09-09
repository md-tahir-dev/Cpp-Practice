/*
Write a program that takes a positive integer (N) as input and calculates the sum of all odd numbers 
from 1 to N using a while loop
*/
#include <iostream>
using namespace std;
void odd(int n)
{
    int sum=0;
    int i = 1;
    while (i<=n)
    {
        if(i%2 != 0)
        {
            sum+=i;
        }
        i++;
    }
    cout<<"Your sum is: "<< sum;
}
int main()
{
    int n;
    cout<<"Enter any positive integer: ";
    cin>>n;
    if(n<0)
    {
        cout<<"Enter the positive value.";
        return -1;
    }
    odd(n);
    return 0;
}