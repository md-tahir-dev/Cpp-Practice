#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2, 5, 7, 8, 10, 13};
    // even and old
    int size = sizeof(arr)/sizeof(int);
    int odd=0;
    int even=0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i]%2==0)
        {
            even ++; 
        }
        else{
            odd ++;
        }
    } 
    cout<<"even = "<<even<<endl;
    cout<<"odd = "<<odd<<endl;
    return 0;
}