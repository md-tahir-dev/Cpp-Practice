#include <iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if(n<2)
    {
        return false;
    }
    for(int i = 2; i <= sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"enter number: ";
    cin>>n;
    if(isPrime(n))
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"not prime";
    }
    return 0;
}