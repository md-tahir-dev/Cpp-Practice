#include <iostream>

using namespace std;
template <typename T>
void reverseArray(T arr[], size_t size)
{
    size_t start = 0;
    size_t end =size-1;
    while (start<end)
    {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    // Test 1: int
    int arr1[] = {10, 20, 30, 40, 50};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Integer array: ";
    reverseArray(arr1, size1);
    cout<<endl;
    
    // Test 2: float
    float arr2[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "Float array: ";
    reverseArray(arr2, size2);
    cout<<endl;
    
    // Test 3: char
    char arr3[] = {'A', 'B', 'C', 'D', 'E'};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    cout << "Character array: ";
    reverseArray(arr3, size3);
    cout<<endl;
    return 0;
}