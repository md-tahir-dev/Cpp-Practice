#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 10, 15,25,35,45,55,65,75,85,95};

    cout << "Address of array: " << arr << endl;
    for(int i =0; i<sizeof(arr)/sizeof(int);i++)
    {    
        cout << "Address of elements: " << &arr[i] << endl;
    }
    cout << "Value of first element: " << arr[0] << endl;
    cout << "Value using pointer: " << *arr << endl;

    return 0;
}