#include<iostream>
#include<vector>
using namespace std;
void intarr1(vector<vector<int>>& arr1, int r1,int c1)
{
    
    for (int i = 0; i < r1; i++)
    {   
        for (int j = 0; j < c1; j++)
        {
            cout << "Enter element for first array at [" << i+1 << "][" << j+1 << "]: ";
            cin>>arr1[i][j];
            cout<<endl;
        }
    }
}
void intarr2(vector<vector<int>>& arr2, int r2,int c2)
{
    
    for (int i = 0; i < r2; i++)
    {   
        for (int j = 0; j < c2; j++)
        {
            cout << "Enter element for second array at [" << i+1 << "][" << j+1 << "]: ";
            cin>>arr2[i][j];
            cout<<endl;
        }
    }
}
void printARR1(vector<vector<int>>& arr1, int r1,int c1)
{
    cout<<"Your first array:- "<<endl;
    for (int i = 0; i < r1; i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void printARR2(vector<vector<int>>& arr2, int r2,int c2)
{
    cout<<"Your second array:- "<<endl;

    for (int i = 0; i < r2; i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int multiply(vector<vector<int>>& arr1,vector<vector<int>>& arr2,vector<vector<int>>& arr3, int r1, int c1, int r2,int c2)
{
    for(int i=0; i<r1;i++)
    {
        for(int j =0; j<c2;j++)
        {
            for(int x =0 ; x<c1;x++)
            {
                arr3[i][j]+= arr1[i][x]*arr2[x][j];
            }
        }
    }
}
void printARR3(vector<vector<int>>& arr3, int r1,int c2)
{
    cout<<"Your final array:- "<<endl;

    for (int i = 0; i < r1; i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int r1;
    int c1;
    int r2;
    int c2;
    cout<<"Enter the rows of first array: ";
    cin>>r1;
    cout<<"Enter the columns of first array: ";
    cin>>c1;
    cout<<"Enter the rows of second array: ";
    cin>>r2;
    cout<<"Enter the columns of second array: ";
    cin>>c2;
    vector<vector<int>> arr1(r1,vector<int>(c1,0));
    vector<vector<int>> arr2(r2,vector<int>(c2,0));
    if (c1 != r2) 
    {
        cout << "Error! size of rows and columns should be same.";
        return -1;
    }
    vector<vector<int>> arr3(r1,vector<int>(c2,0));
    intarr1(arr1,r1,c1);
    intarr2(arr2,r2,c2);

    printARR1(arr1,r1,c1);
    printARR2(arr2,r2,c2);

    multiply(arr1,arr2,arr3,r1,c1,r2,c2);
    printARR3(arr3,r1,c2);
}