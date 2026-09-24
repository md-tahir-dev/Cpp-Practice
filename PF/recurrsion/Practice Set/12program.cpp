// SUM OF ARRAY
#include <iostream>
using namespace std;
int SUM(int arr[],int n)
{
    if(n==0)
    {
        return 0;
    }
    return arr[n-1] + SUM(arr, n-1);
}
int main()
{
    int arr[]={9,7,5,4};
    int sz=sizeof(arr)/sizeof(arr[0]);
    cout<<SUM(arr,sz);
    return 0;
}