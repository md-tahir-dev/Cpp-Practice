/*
Write a C++ program that takes an integer number from the user and calculates and displays the sum 
of all its digits.
*/
#include <iostream>
using namespace std;
int countDigit(int n)
{
    if (n == 0)
    {    
        return 1;
    }
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

void digitsum(int n)
{
    int sum=0;
    while (n!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    cout<<sum;

}
int main()
{
    int n;
    cout<<"Enter value: ";
    cin>>n;
    digitsum(n);
    return 0;
}