#include<iostream>
using namespace std;
void printARR(int arr[3][3],int N)
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
void multiplyARR(int arr[3][3],int N,int num)
{
    for(int i = 0; i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j]*=num;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int num;
    int arr[3][3]=
    {
        2,9,5,
        7,1,8,
        7,3,5
    };
    printARR(arr,3);
    cout<<"Enter a number for multiply: ";
    cin>>num;
    multiplyARR(arr,3,num);
}