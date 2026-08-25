/*
Write a program that takes a positive integer (N) as input and calculates the sum of all number (1 to 
N) using a while loop
*/
#include <iostream>
using namespace std;
int sum(int n)
{
    int sum = 0;
    int i=1;
    while (i<=n)
    {
        sum+=i;
        i++;
    }
    return sum;
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
    cout<<"Sum is: "<<sum(n);
    return 0;
}