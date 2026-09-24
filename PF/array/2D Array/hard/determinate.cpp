#include <iostream>

using namespace std;
void intput(int arr[][2])
{
    cout<<"Enter value: ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>arr[i][j];
        }
        
    }
}
void multi(int arr[][2])
{
    cout<<(arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]);
}
int main()
{
    int arr[2][2];
    intput(arr);
    return 0;
}