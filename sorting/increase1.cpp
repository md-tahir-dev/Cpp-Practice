// through selection sort
#include<iostream>
using namespace std;
int sort(int arr[],int size)
{
    for (int i = 0; i < size-1; i++)
    {   
        int smallestIND=i;
        for(int j = i+1; j<size;j++)
        {
            if(arr[j]<arr[smallestIND])
            {
                smallestIND=j;
            }
        }
        swap(arr[i], arr[smallestIND]);
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
    int arr[]={4,1,5,2,3};
    int size = sizeof(arr)/sizeof(int);
    sort(arr,size);
    printARR(arr,size);

}