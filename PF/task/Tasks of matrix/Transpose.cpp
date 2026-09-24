#include<iostream>
#include<vector>
using namespace std;
void intarr(vector<vector<int>>&arr,int rows,int columns)
{
    cout<<"kindly enter matrix:- \n";
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0 ; j < columns ; j++)
        {
            cin>>arr[i][j];
        }
    }
}
void printARR(vector<vector<int>>&arr,int rows,int columns)
{
    cout<<"Your endered matrix:-\n";
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0 ; j < columns ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
}
vector<vector<int>>isTranspose(vector<vector<int>>&arr,int rows, int columns)
{
    vector<vector<int>>arrtranspose(columns,vector<int>(rows,0));    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arrtranspose[j][i]=arr[i][j];
        }
        
    }
    return arrtranspose;
    
}
int main()
{
    int rows, columns;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>columns;
    vector<vector<int>>arr(columns,vector<int>(rows,0));
    intarr(arr,rows,columns);

    printARR(arr,rows,columns);

    vector<vector<int>>arr1=isTranspose(arr, rows, columns);
    printARR(arr1,rows,columns);
}