#include<iostream>
using namespace std;
int reverseNumber(int n, int result)
{
    if(n == 0)
    {
        return result;
    }

    return reverseNumber(n / 10, result * 10 + n % 10);
}
int main()
{ 
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<reverseNumber(n,0);
}