#include<iostream>
using namespace std;
int reverse(int arr[], int size)
{
    int start = 0, end = size-1;
    while (start<end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    
}
int main()
{
    int arr[]={6,5,4,3,2,1};
    int size = 6;
    reverse(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}