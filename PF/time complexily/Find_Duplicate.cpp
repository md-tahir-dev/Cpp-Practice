#include <iostream>
using namespace std;
void Find_Duplicate(int arr[],int size)
{
    int duplicate;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {
            if(arr[i]==arr[j])
            {
                duplicate=arr[i];
                cout<<"Duplicate found: "<<duplicate<<endl;
                return;
            }
        }
        
    }
    cout<<"No duplicate found!!!";
    return;
}
int main()
{
    int arr[]= {1, 5, 3, 7, 2, 5};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    Find_Duplicate(arr,size);
    return 0;
}