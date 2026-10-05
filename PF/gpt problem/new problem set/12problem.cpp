#include <iostream>
using namespace std;
void fun(int arr[],int size)
{
    int bestStart=-1, bestEnd=-1;
    int maxLen=0;
    int d1=-1, d2 = -1;
    for(int i = 0 ; i <size; i++)
    {
        int first = arr[i];
        int second = -1;
        int distinct = 1;
        for(int j = i; j<size; j++)
        {
            if(arr[j]!=first&&second==-1)
            {
                second=arr[j];
                distinct++;
            }
            else if(arr[j]!=first&&arr[j]!=second)
            {
                break;
            }
            if(distinct==2)
            {
                int lenght=j-i+1;
                if(lenght>maxLen)
                {
                    maxLen=lenght;
                    bestStart=i;
                    bestEnd=j;
                    d1=first;
                    d2=second;
                }
            }
        }
    }
    if(bestStart!=-1)
    {   cout<<"Longest subarray: ";
        for(int i = bestStart;i<=bestEnd;i++)
    {
        cout<<arr[i]<<" ";
    }} 
    cout<<"\nLength = "<<maxLen<<endl;
    cout<<"Distinct values = "<<d1<<" and "<<d2<<endl;   
}
int main()
{
    int arr[] = {1, 2, 1, 3, 4, 3, 3, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    fun(arr,size);
    return 0;
}