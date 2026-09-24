#include <iostream>
#include<vector>
using namespace std;
void Find_Duplicate(vector<int>dupli,int arr[],int size)
{
    cout<<"Deplicate element is: ";
    for (size_t i = 0; i < size; i++)
    {
        dupli[arr[i]]++;
        if(dupli[arr[i]]==2)
        {
            cout<<arr[i];
        }
    }
    cout<<endl;
    return;
}
int main()
{
    int arr[]= {1, 5, 3, 7, 2, 5};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int max= arr[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    vector<int>dupli(max+1,0);
    Find_Duplicate(dupli,arr,size);
    return 0;
}