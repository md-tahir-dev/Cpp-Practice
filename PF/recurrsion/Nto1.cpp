/*
Print numbers from N to 1
Input: 5
Output: 5 4 3 2 1
*/
#include<iostream>
using namespace std;
void series(int n)
{
    if(n==1)
    {
        cout<<1;
        return;
    }
    if(n<=0)
    {
        cout<<"Re-enter!!!";
        return;
    }
    cout<<n<<"\t";
    series(n-1);
}
int main()
{
    int n;
    cin>>n;
    series(n);
    return 0;
}