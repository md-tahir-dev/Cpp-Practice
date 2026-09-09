#include <iostream>
using namespace std;
int isPrime(int n)
{
    for (size_t i = 2; i < n; i++)
    {
        if(n%i==0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    if(isPrime(n)==1)
    {
        cout<<"Your entered number is prime";
    }
    else
    {
        cout<<"Your entered number is not prime";
    }
    return 0;
}