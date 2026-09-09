#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    int m = 5;
    for(int x = 1; x<m; x++)
    {
        for(int j = m;j>x;j--)
        {
            cout<<" ";
        }
        // cout<<endl;
        for(int j = 0;j<x+1;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0;j<(i+1);j++)
        {
            cout<<" ";
        }
        // cout<<endl;
        for(int j = 0;j<n-i;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    
}