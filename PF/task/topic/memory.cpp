#include <iostream>
using namespace std;

int main()
{
    int arr[] = {100, 200, 300, 400, 500};

    cout << "The given array is: ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    cout << "For index 0, arr[0]: " << arr[0] << endl;
    cout << "*(arr + 0) = " << *(arr + 0) << endl;
    cout << "Address of arr[0] = " << &arr[0] << endl;

    cout << endl;

    cout << "For index 1, arr[1]: " << arr[1] << endl;
    cout << "*(arr + 1) = " << *(arr + 1) << endl;
    cout << "Address of arr[1] = " << &arr[1] << endl;

    cout << endl;

    // Difference between addresses
    cout << "Address difference: "
         << (char*)&arr[1] - (char*)&arr[0]
         << " bytes" << endl;

    return 0;
}