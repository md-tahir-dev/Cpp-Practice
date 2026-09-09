#include<iostream>
using namespace std;
int linear(int arr[], int size, int target){
    for(int i = 0; i<size; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}   

int main()
{
    int arr[]={1, 7, 3, 9, 2, 8};
    int size=6;
    int target;
    cout<<"enter value: ";
    cin>>target;
    cout<<linear(arr,size,target);
    return 0;
}