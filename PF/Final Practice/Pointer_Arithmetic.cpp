#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {10, 20, 30};
    int* p = arr;       // points to arr[0]
    cout << *(p+1);     // prints 20

    return 0;
}