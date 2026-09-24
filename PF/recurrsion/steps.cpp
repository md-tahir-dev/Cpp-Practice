#include<iostream>
using namespace std;
int count(int n)
{
    if(n<=0)
    {
        cout<<"Reenter greater than 0";
        return -1;
    }
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    return count(n-2)+count(n-1);
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<count(n);
    return 0;
}