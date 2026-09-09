#include<iostream>
using namespace std;
int main()
{
    int arr[] = {10, 20, 30, 40};

    int* ptr = arr;
    // int** ptr = arr;

    cout << arr[0] << endl;       // 30
    cout << *(arr + 0) << endl;   // 30
    cout << ptr[4] << endl;       // 30
    cout << *(ptr + 0) << endl;  // 30
    return 0;
}