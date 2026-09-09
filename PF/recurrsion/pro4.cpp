// Sum of n number like 5 = 5+4+3+2+1
#include <iostream>
using namespace std;
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n + sum(n-1);
}
int main()
{
    int n = 5;
    cout<<sum(n);
}