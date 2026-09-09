#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[]={8, 3, 15, 1, 9};
    int size = sizeof(arr)/sizeof(int);
    int valmax=INT_MIN;
    for(int i = 0; i<size; i++)
    {
            
                valmax=max(arr[i],valmax);
            
    }
    cout<<"Largest = "<<valmax;
    
    return 0;
}