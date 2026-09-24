// Write a program to: • Dynamically allocate memory for N integers • Take input from user • Find minimum and maximum number • Finally, release the memory
#include <iostream>
#include <climits>

using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int* arr=new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter element for "<<i+1<<": ";
        cin>>arr[i];
    }
    int min= INT_MAX;
    int max= INT_MIN;
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"Minimin value is: "<<min<<endl;
    cout<<"Maximin value is: "<<max<<endl;
    
    return 0;
}