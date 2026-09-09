#include <iostream>

using namespace std;
template <typename T>
T findElement(T arr[],size_t size, T target)
{
    for (size_t i = 0; i < size; i++)
    {
        if(target==arr[i])
        {
            return i;
        }
    }
    return -1;
    
}
int main()
{
    int arr[]={10,20, 30, 40, 50};
    int target = 30;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Int index: "<<findElement(arr,size,target)<<endl;
        // Test with double
    double doubleArr[] = {10.5, 20.5, 30.5, 40.5, 50.5};
    double doubleTarget = 30.5;

    size_t doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "Double index: "
         << findElement(doubleArr, doubleSize, doubleTarget)
         << endl;


    // Test with float
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    float floatTarget = 3.3f;

    size_t floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "Float index: "
         << findElement(floatArr, floatSize, floatTarget)
         << endl;
    return 0;
}