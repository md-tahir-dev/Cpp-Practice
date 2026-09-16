// Find the Missing Number
#include <iostream>
using namespace std;
int is_find(int arr[],int size)
{
    int expeSUM=(size+1)*(size+2)/2;
    int autSUM=0;
    for (size_t i = 0; i < size; i++)
    {
        autSUM+=arr[i];
    }
    return expeSUM-autSUM;
}
int main()
{
    int arr[] = {2, 4, 5, 6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<is_find(arr,size);
    return 0;
}
// Output: 3