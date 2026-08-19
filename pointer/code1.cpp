#include <iostream>
using namespace std;
int main()
{
    int * arr= new int[5]{1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    arr=nullptr;
    return 0;
}