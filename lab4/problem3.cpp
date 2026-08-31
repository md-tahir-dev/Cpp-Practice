#include<iostream>
using namespace std;
int power(int n,int m)
{
    if(m==0)
    {
        return 1;
    }
    if (m % 2 == 0)
        return power(n, m / 2) * power(n, m / 2);   
    return n * power(n, m / 2) * power(n, m / 2);
}
int count(int n)
{
    int c=0;
    while (n)
    {
        n/=10;
        c++;
    }
    return c;
}
bool isArmstrong(int n)
{
    int x = count(n);
    int temp = n,sum = 0;
    while (temp)
    {
        int r = temp % 10;
        sum += power(r,x);
        temp=temp/10;
    }
    return (sum==n);
}
int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    if(isArmstrong(n))
    {
        cout<<"Number is Armstrong.";
    }
    else
    {
        cout<<"Number isn't Armstrong.";
    }
    return 0;
}