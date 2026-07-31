/*
Write a program that displays the following using do-while loop. Ask user for starting
and ending point.
4 4 4 4
3 3 3
2 2
1 
*/

#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the starting point: ";
    cin>>n;
    // for(int i = 0; i<n; i++)
    // {
    // k=n-i;
    //     for (int j = 1; j<=n-i; j++)
    //     {
    //         cout<<k<<" ";
    //     }
    // cout<<endl;
    // }
    int i = 0;  
    do{
    k=n-i;
        for (int j = 1; j<=n-i; j++)
        {
            cout<<k<<" ";
        }
    cout<<endl;
    i++;
    }
    while(i<n);
}