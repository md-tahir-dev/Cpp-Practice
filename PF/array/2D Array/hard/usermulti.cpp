#include<iostream>
#include<vector>
using namespace std;
int count(int arr[3][3])
{
    int count=0;
    for (int i = 0; i < 3; i++)
    {
        if(arr[i][0]==0)
        {
            break;
        }
        count++;
    }
    return count;
}
void inputARR(vector<vector<int>>& arr, int N)
{
    for (int i = 0; i < N; i++)
    {   
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    } 
}
void printARR(vector<vector<int>>& arr, int N)
{
    cout<<"Here is array!!!"<<endl;
    for(int i = 0; i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void multiplyARR(vector<vector<int>> arr, int N, int num)
{
    for(int i = 0; i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j]=arr[i][j]*num;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int num;
    int N;
    cout << "Enter matrix size: ";
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    cout<<"Enter Elements:-"<<endl;
    inputARR(arr,N);
    // int N=count(arr);
    printARR(arr,N);
    cout<<"Enter a number for multiply: ";
    cin>>num;
    multiplyARR(arr,N,num);
}