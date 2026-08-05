
#include<iostream>
using namespace std;
bool isPrime (int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }    
    }
    return true;
}
int sort(int arr[], int size)
{
    for(int i = 0; i<size-1; i++)
    {   
        for(int j=1;j<size;j++)
        {   
            int curr = arr[j];
            int previous = arr[j-1];
            if(isPrime(curr)&&!isPrime(previous))
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
    int arr[]={10,3,15,19,23,2,6,17};
    int size = sizeof(arr)/sizeof(int);
    // cout<<size;
    sort(arr,size);
    printARR(arr,size);
    return 0;
}
