#include <iostream>

using namespace std;

int main()
{
    int arr[]= {3,8,2,5,7,6,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int w = 3;
    int maxStart =0;
    int currSUM=0;
    for (size_t i = 0; i < w; i++)
    {
        currSUM+=arr[i];
    }
    int maxx =currSUM;
    for (size_t i = 1; i <= n-w; i++)
    {
        currSUM=currSUM-arr[i-1]+arr[i+w-1];
        if(currSUM>maxx)
        { 
            maxStart=i;
            maxx=currSUM;
        }
    }
    cout<<"Maximin sum is: "<<maxx<<endl;
    cout<<"Maximin sum array is: "<<endl;
    for(int i = maxStart; i<w+maxStart;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
