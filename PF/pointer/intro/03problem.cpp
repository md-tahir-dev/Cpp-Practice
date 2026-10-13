#include <iostream>
using namespace std;
int main()
{
    const int N = 5;
    int arr[N] = {11, 22, 33, 44, 55};
    int arr2[3]={4,7,2};
    int *ptr = arr;
    cout << "Base address of arr is: " << arr << endl;
    cout << "ptr is: " << ptr << endl
         << endl;
    ptr=arr2;
    for (int i = 0; i < N; i++)
    {
        // cout<<"Element # "<<i<<":   "<<&ptr[i]<<"       "<<ptr[i]<<endl;
        // cout<<"Element # "<<i<<":   "<<&arr[i]<<"       "<<ptr[i]<<endl;
        // cout << arr + i << "    " << *(arr + i) << "         " << ptr + i << "    " << *(ptr + i) << endl;
        // // i units = i * 4 bytes
        // cout<< arr[i]<<"  "<<*(arr+i)<<endl;
        // cout<< ptr[i]<<"  "<<*(ptr+i)<<endl;
        ptr= &arr[i];
        cout<<ptr<<"    "<<*ptr<<endl;
    }

    return 0;
}