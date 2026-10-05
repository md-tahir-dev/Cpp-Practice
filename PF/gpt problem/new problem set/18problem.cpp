#include <iostream>

using namespace std;
void fun(int arr[], int size, int target)
{
    int bestStart=-1,bestEnd=-1;
    for(int i = 0;i<size;i++ )
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] + arr[j] == target)
            {
                bestStart=i;
                bestEnd=j;
                if(bestStart!=-1){
                    cout<<"Indices: "<<bestStart<<" "<<bestEnd<<endl;
                    cout<<"Values: "<<arr[bestStart]<<" "<<arr[bestEnd]<<endl;}
                    return;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 7, 11, 15, 3, 7};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr,size,target);
    return 0;
}