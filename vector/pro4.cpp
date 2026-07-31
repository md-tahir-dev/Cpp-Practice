#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[]={8, 3, 15, 1, 9};
    int size = sizeof(arr)/sizeof(int);
    int valmin=INT_MAX;
    for(int i = 0; i<size; i++)
    {
            
                valmin=min(arr[i],valmin);
            
    }
    cout<<"Smallest is = "<<valmin;
    
    return 0;
}