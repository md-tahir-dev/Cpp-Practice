#include<iostream>
using namespace std;
int factofn(int n)
{
    if(n ==0)
    {
        return 1;
    }
    if(n < 0)
    {
        cout << "Re-enter a number greater than or equal to 0";
        return 0;
    }
    return n * factofn(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<factofn(n);
}