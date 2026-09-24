#include<iostream>
using namespace std;
void printNUM(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<"\t";
    printNUM(n-1);
}
int main()
{
    int n;
    cin>>n;
    printNUM(n);    
}