// Largest Digit
#include <iostream>
#include<algorithm>
using namespace std;
int largestDigit(int n)
{
    if(n==0)
    {
        return 0;
    }
    return max(n % 10, largestDigit(n / 10));
}
int main()
{
    int n =6;
    cout<<largestDigit(n);
    return 0;
}