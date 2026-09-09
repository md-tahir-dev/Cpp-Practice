#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return n * factorial(n-1);
}
bool isstrong(int n)
{
    int copy = n; 
    int sum=0;
    while (n>0)
    {
        int r = n % 10;
        sum += factorial(r);
        n = n /10;
    }
    return (sum==copy);
}
int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    if(isstrong(n))
    {
        cout<<"IsStrong.";
    }
    else
    {
        cout<<"Not IsStrong";
    }
}