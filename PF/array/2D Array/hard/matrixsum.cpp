#include<iostream>
#include<vector>
using namespace std;
void inputARR(vector<vector<int>>&arr,int N)
{   
    cout<<"Enter Element:-"<<endl;
    for(int i = 0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>arr[i][j];
        }
    }
}
void printARR(vector<vector<int>>&arr,int N)
{
    cout<<"Matrix:- "<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sumrow(vector<vector<int>>&arr,int N)
{
    cout<<"Rows sums:- ";
    int sum;
    for(int i = 0; i<N; i++)
    {
        sum=0;
        for (int j = 0; j <N; j++)
        {
            sum+=arr[i][j];
        }
        cout<<endl;
        cout<<"Row "<<i+1<<" = "<<sum;
    }
    cout<<endl;
}
void sumcolumns(vector<vector<int>>&arr,int N)
{
    cout<<"Rows sums:- ";
    int sum;
    for(int i = 0; i<N; i++)
    {
        sum=0;
        for (int j = 0; j <N; j++)
        {
            sum+=arr[j][i];
        }
        cout<<endl;
        cout<<"column "<<i+1<<" = "<<sum;
    }
    cout<<endl;
}
int main()
{
    int N;
    cout<<"Enter N: ";
    cin>>N;
    vector<vector<int>> arr(N,vector<int>(N));
    inputARR(arr,N);
    printARR(arr,N);
    sumrow(arr,N);
    sumcolumns(arr,N);
}