// Palindrome Number
#include <iostream>

using namespace std;
int ReversetDigit(int n,int rev=0)
{
    if(n==0)
    {
        return rev;
    }
    return ReversetDigit(n/10,rev*10+(n%10));
}
bool isPalindrome(int n,int rev=0)
{
    int copy=n;
    return copy==ReversetDigit(n);
}
int main()
{
    int n=1261;
    if(isPalindrome(n))
    {
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}