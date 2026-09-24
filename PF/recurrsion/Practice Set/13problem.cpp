#include <iostream>
#include <algorithm>
using namespace std;
bool isSorted(int arr[],int n)
{
    if (n == 0 || n == 1) return true;
    if (arr[n-1] < arr[n-2]) return false;
    return isSorted(arr, n-1);
}

int main()
{
    int arr[]={1,2,8,4,5,6};
    int sz=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,sz);
    return 0;
}