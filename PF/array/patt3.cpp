/*
    1
   121
  12321
 1234321
123454321   
*/
#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    for(int i = 0; i<n;i++)
    {
        // spaces
        for(int j = 0;j<n-i-1;j++)
        {
            cout<<" ";
        }
    // cout<<endl;
        for(int j=1;j<=i+1;j++)
        {
        // num first
            cout<<j;
        }
        for(int j =i; j > 0; j--)    
        {
        // num second
            cout<<j;
        }
        cout<<endl;
    }
}
