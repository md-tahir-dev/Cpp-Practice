#include <iostream>
using namespace std;
void bubbleshot(int arr[],int n) 
{
    for(int i = 0; i<n-1;i++)
    {   
        bool isSWAP = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                isSWAP=true;
            }
        }
        if(isSWAP==false)
        {
            if(i==0)
            {
                cout << "Array is already sorted" << endl;
                return ;
            }
        }
    }
}
void printARR(int arr[],int n){
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    // int arr[]={4,1,5,2,3};
    int arr[]={1,2,4,3};
    int size = sizeof(arr)/sizeof(int);
    int n = size;
    bubbleshot(arr,n);
    printARR(arr, n);
    cout<<endl;
    return 0;
}