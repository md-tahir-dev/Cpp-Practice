#include <iostream>
using namespace std;
void sorted_arr(int arr[],int n)
{
    for (size_t i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-1-i;j++)
        {   
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }   
        }
    }
}
int is_find(int arr[],int n)
{
    int copy=arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if(copy!=arr[i])
        {
            return copy;
        }
        copy++;
    }
    
}
int main()
{
    int arr[]={4,1,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array without sorting: ";
    cout<<endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"Array with sorting: "<<endl;
    sorted_arr(arr,size);
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"Missing number in array is: ";
    cout<<is_find(arr,size);
    return 0;
}