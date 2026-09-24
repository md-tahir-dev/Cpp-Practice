#include<iostream>
using namespace std;
int main()
{
    int arr[] = {5, 12, 8, 20, 15};
    int target;
    int size = sizeof(arr)/sizeof(int);
    bool print=false;
    cout<<"Enter a value: "<<endl;
    cin>>target;
    for(int i=0; i<size; i++)
    {
        if(arr[i]==target)
        {   
            print=true;
            // cout<<"Found";
            break;
        }
        
            // cout<<"Not Found";
        }
    if(print)
    {    cout<<"found";
    }
    else
    {
        cout<<"Not Found";
    }
    return 0;
}