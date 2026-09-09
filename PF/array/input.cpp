#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<< "ENTER SIZE OF ARRAY: ";
    cin>>size;
    int arr[size];
    // int i;
    for(int i = 0;i<size;i++)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    for(int i = 0;i<size;i++)
    {
    cout<<arr[i]<<" ";
    }
}