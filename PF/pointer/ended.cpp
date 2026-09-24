#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    // cout << *(ptr + 0);  // 10
    // cout<<endl;
    // cout << *(ptr + 1);  // 20
    // cout<<endl;
    // cout << *(ptr + 2);  // 30
    // cout<<endl;
    // cout << *(ptr + 3);  // 40
    // cout<<endl;
    // cout << *(ptr + 4);  // 50
    for (int i = 0;i<5 ; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout<<endl;
    cout << sizeof(arr)/sizeof(int) << endl;
    return 0;
}