#include<iostream>
using namespace std;
void sorting(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {   
        bool isSwap = false;
        for(int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap)
        {
            if (i==0)
            {
                cout<<"Array is already sorted";
                return;
            }
        }
    }
}
int printARR(int arr[], int n)
{
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={5,2,3,1,4};
    int n = sizeof(arr)/sizeof(int);
    sorting(arr,n);
    printARR(arr,n);
    return 0; 
}