#include <iostream>
using namespace std;
void multiply(int arr1[][3], int arr2[][3], int arr3[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr3[i][j]=arr1[i][j]*arr2[i][j];
        }
        
    }
}
void printARR(int arr3[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int arr1[3][3]={
        1,2,3,
        4,5,6,
        7,8,9
    };
    int arr2[3][3]={
        1,2,3,
        4,5,6,
        7,8,9
    };
    int arr3[3][3];
    multiply(arr1,arr2,arr3);
    printARR(arr3);
    return 0;
}