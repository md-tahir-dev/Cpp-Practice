#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int low, int high, int target)
{
    if(low>high)
    {
        return -1;
    }
    int mid = low + (high-low)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch(arr,low, mid-1, target);  //left 
    }
    else
    {
        return binarySearch(arr, mid+1,high, target); //right 
    }

}
int main()
{
    int arr[]={2,5,6,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = 4;
    cout<<binarySearch(arr,low,high,6);
    return 0;
}