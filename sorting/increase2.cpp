#include<iostream>
using namespace std;
int sort(int arr[],int n)
{
    for(int i = 1; i<n; i++)
    {
        int curr=arr[i];
        int previous = i-1;
        while (previous>=0&&arr[previous]>curr)
        {
            arr[previous+1]=arr[previous];
            previous--;
        }
        arr[previous+1]=curr;
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
    int arr[]={4,1,7,10,5,2,3};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,n);
    printARR(arr,n);
    return 0;
}