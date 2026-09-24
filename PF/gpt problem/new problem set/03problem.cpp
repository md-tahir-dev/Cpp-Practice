#include <iostream>
using namespace std;
int duplicate(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    if(duplicate(arr,size)==-1)
    {
        cout<<"No Duplicate element in array";
    }
    else
    {
        cout<<"\""<<duplicate(arr,size)<<"\" is the duplicate element.";
    }
    return 0;
}