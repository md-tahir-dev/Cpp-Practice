#include<iostream>
using namespace std;
void PrintFIB(int n)
{
    if(n<1)
    {
        cout<<"Re-enter greater then 1";
    }
    int pre2 = 0;
    int pre1 = 1;
    cout<<pre2<<" ";
    if(n==1)
    {
        return ;
    }
    cout<<pre1<<" ";
    for(int i = 3;i<=n;i++)
    {
        int curr = pre1+pre2;
        cout<<curr<<" ";
        pre2=pre1;
        pre1=curr;
    }
}
int main()
{   
    // add git
    int n;
    cout<<"Enter number: ";
    cin>>n;
    PrintFIB(n);
}