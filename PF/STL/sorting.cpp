#include <iostream>
using namespace std;
void printARR(int arr[],int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sort(int arr[],int size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        for(size_t j = 0; j < size-i-1; j++)
        {
            if(arr[j]<arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    printARR(arr,size);
}
int main()
{
    int arr[]={1,5,3,7,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    printARR(arr,size);
    cout<<"After sorting: ";
    sort(arr,size);

    return 0;
}