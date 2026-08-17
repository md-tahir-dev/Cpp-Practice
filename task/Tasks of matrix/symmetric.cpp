#include<iostream>
#include<vector>
using namespace std;
void intarr(vector<vector<int>>&arr,int n)
{
    cout<<"kindly enter matrix:- \n";
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin>>arr[i][j];
        }
    }
}
void printARR(vector<vector<int>>&arr,int n)
{
    cout<<"Your endered matrix:-\n";
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
}
bool issymmetric(vector<vector<int>>&arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]!=arr[j][i])
            return false;
        }
        
    }
    return true;
    
}
int main()
{
    int rows, columns;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>columns;
    if(rows!=columns)
    {
        cout<<"To check that matrix symmetric, the number of rows and columns should be equal.";
        return 0;
    }
    int n=rows;
    vector<vector<int>>arr(n,vector<int>(n,0));
    intarr(arr,n);
    printARR(arr,n);
    if(issymmetric(arr,n))
    {
        cout<<"Your matrix is symmetric.";
    }
    else
    {
        cout<<"your matrix isn't symmetric";
    }
}