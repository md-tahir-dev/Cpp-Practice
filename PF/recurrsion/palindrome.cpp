#include<iostream>
using namespace std;
int reverseNUM(int n, int reverse)
{
    if(n==0)
    {
        return reverse;
    }
    int digit = n%10;
    return reverseNUM(n / 10, reverse * 10 + digit);
}
void checkPalindrome(int n)
{
    int reverse=reverseNUM(n,0);
    if(n==reverse)
    {
        cout<<"Number is palindrome";
    }
    else
    {
        cout<<"Number isn't palindrome";
    }
}
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    checkPalindrome(n);
    return 0;
}