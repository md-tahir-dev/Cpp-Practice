#include<iostream>
using namespace std;
void series(int n,int m =1)
{
    if(n<=0)
    {
        cout<<"Re-enter!!!";
        return;
    }    
    if(m==n)
    {
        cout<<m;
        return;
    }

    cout<<m<<"\t";
    series(n,m+1);

    return;

}
int main()
{
    int n;
    cin>>n;
    series(n);
    return 0;
}