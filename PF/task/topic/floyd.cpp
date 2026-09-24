#include<iostream>
using namespace std;
int floyd(int n)
{
    int num = 1; 
    for(int i = 1; i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {  
                cout<<num<<" ";
                num=1 - num;
            }
            cout<<endl;
    }
}
int main()
{
    int n=5;
    floyd(n);
}
