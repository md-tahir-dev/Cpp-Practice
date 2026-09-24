// Reverse Digit
#include <iostream>
#include<algorithm>
using namespace std;
int ReversetDigit(int n,int rev=0)
{
    if(n==0)
    {
        return rev;
    }
    return ReversetDigit(n/10,rev*10+(n%10));
}
int main()
{
    int n =6543;
    cout<<ReversetDigit(n);
    return 0;
}