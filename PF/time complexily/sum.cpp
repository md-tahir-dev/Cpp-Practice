#include <iostream>
using namespace std;
void findSUM(int arr[],int size, int target)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i+1; j <size; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                cout<<"Index "<<i<<" and Index "<<j;
                return;
            }
        }
        
    }
    cout<<"Target not found";
    return;
}
int main()
{
    // int arr[]={2, 7, 11, 15};
    int arr[]={4, 3, 8, 2, 9};
    size_t size = sizeof(arr)/sizeof(int);
    int target;
    cout<<"Enter target: ";
    cin>>target;
    findSUM(arr,size,target);
    return 0;
}