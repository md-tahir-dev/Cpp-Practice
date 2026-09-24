// int sumDigits(int n)
#include <iostream>

using namespace std;
int sumDigits(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n%10+sumDigits(n/10);
}
int main()
{   
    int n=12345;
    cout<<sumDigits(n);
    return 0;
}