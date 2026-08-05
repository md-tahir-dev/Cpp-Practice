/*this is input arr[]={1,1,0,1,0,1,0,1,1,0}
output should 0 0 0 0 1 1 1 1 1 1*/
#include<iostream>
using namespace std;

int sort(int arr[], int size)
{
    for(int i = 0; i<size-1; i++)
    {   
        for(int j=1;j<size;j++)
        {   
            int curr = arr[j];
            int previous = arr[j-1];
            if(curr<previous)
            {
                swap(arr[j],arr[j-1]);
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
    int arr[]={1,1,0,1,0,1,0,1,1,0};
    int size = sizeof(arr)/sizeof(int);
    // cout<<size;
    sort(arr,size);
    printARR(arr,size);
    return 0;
}
