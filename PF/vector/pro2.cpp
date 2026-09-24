#include<iostream>
using namespace std;
int main()
{
    int arr[] = {5, 10, 15, 20};
    int size=sizeof(arr)/sizeof(int);
    int sum = 0;
    for(int i = 0; i<size; i++)
    {
        sum+=arr[i];
    }
    cout<<"Sum = "<<sum;
    return 0;
}