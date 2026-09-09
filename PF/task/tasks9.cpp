#include<iostream>
using namespace std; 
bool isPerfect(int n)
{
    int sum =0;
    for(int i = 1; i<=n/2; i++)
    {
        if(n%i==0)
        {
            sum = sum + i;
        }
    }
    return sum==n;
}
int main()
{
    int n;
    cout<<"Enter a perfect nummber: ";
    cin>>n;
    // cout<<isPerfect(n);
    if(isPerfect(n)==true)
    {
        cout<<n<<" is a Perfect Number";
    }
    else
    {
        cout<<n<<" isn't a Perfect Number";
    }
    return 0;
}