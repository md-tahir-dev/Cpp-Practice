#include <iostream>

using namespace std;
void print(int arr[],int size, int target)
{
    int sum=0;
    int start_address,end_address;
    for(int i = 0; i<size;i++)
    {   sum=0;
        sum+=arr[i];
        for(int j=i+1;j<size;j++)
        {sum+=arr[j];
        if(sum==target)
        {
           start_address=i;end_address=j; 
           for(int a = start_address; a<=end_address;a++)
           {
                cout<<arr[a]<<" ";
           }
           cout<<endl;
        //    return;
        }
        // if(sum>target)
        // {
        //     break;
        // }
    }
    }
}
int main()
{
    int arr[] = {2, 4, 7, 3, 5, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;
    print(arr,size,target);
    return 0;
}