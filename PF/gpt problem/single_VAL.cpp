#include <iostream>
using namespace std;
int single_VAL(int* arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        int count=0;
        for (int j = 0; j < size; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count==1)
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    int arr[]={5,4,1,2,1,4,5};
    int size = sizeof(arr)/ sizeof(arr[0]);
    if(single_VAL(arr,size)==-1){
        cout<<"No single value in it.";
    }
    else
    {
        cout<<"single value is: "<<single_VAL(arr,size);
    }
    return 0;
}