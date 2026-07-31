#include<iostream>
using namespace std;
int main()
{   
    int arr[] = {5, 12, 8, 20, 15};    
    int target;
    int val = -1;
    int size = sizeof(arr)/sizeof(int);
    cout<<"Enter a value: "<<endl;
    cin>>target;
    for(int i=0; i<size; i++)
    {
        if(target==arr[i])
        {
            val =i;
            break;
        }
    }
       cout<<val;
    return 0;
}

    
