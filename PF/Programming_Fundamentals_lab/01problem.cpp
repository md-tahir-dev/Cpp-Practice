// Write a program using a function that takes an array of n integers and returns the second largest
// number.
#include <iostream>
#include <climits>

using namespace std;
int secondLARGEST(int arr[],int n)
{
    if(n<2)
    {
        cout<<"You can not enter numbers below 2!!!"<<endl;
        return -1;
    } 
    int largest = arr[0];
    int second = INT_MIN;
    for (size_t i = 1; i < n; i++)
    {
        if(arr[i]>largest)
        {
            second=largest;
            largest=arr[i];
        }
        else if(arr[i]>second&&arr[i]!=largest)
        {
            second=arr[i];
        }
    }
    if(second==INT_MIN)
    {
        cout<<"All Element are equal."<<endl;
        return -1;
    }
    return second;
}
int main()
{
    int n;
    cout<<"Enter the total number that you want enter: ";
    cin>>n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter element for "<<i+1<<": ";
        cin>>arr[i];
        cout<<endl;
    }
    int result = secondLARGEST(arr,n);
    if(result!=-1)
    {
        cout<<"Second largest element is: "<<result;
    }
    
    return 0;
}