#include <iostream>
// int* getLocalPointer() 
// {
//     int localVal = 100;
//     return &localVal; // WARNING: localVal will be destroyed
// }

using namespace std;

int main()
{

    // int* ptr = getLocalPointer(); // ptr is immediately dangling

    int* arr=new int [2]{1,2};
    for (size_t i = 0; i < 2; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    arr=nullptr;
    if (arr == nullptr)
{
    cout << "Pointer is empty";
}
    for (size_t i = 0; i < 2; i++)
    {
        cout<<arr[i]<<" ";
    }


return 0;


}