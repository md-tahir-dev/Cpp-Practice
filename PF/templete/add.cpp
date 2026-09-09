#include <iostream>

using namespace std;
template <typename T>
T addarray(T* arr,size_t size)
{
    T sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int intarr[]={10 ,20, 30 ,40};
    size_t size1 = sizeof(intarr)/sizeof(intarr[0]);
    cout<<"Output: "<<addarray(intarr,size1)<<endl;
    float floatarr[]={1.5f, 2.5f, 3.0f};
    size_t size2 = sizeof(floatarr)/sizeof(floatarr[0]);
    cout<<"Output: "<<addarray(floatarr,size2)<<endl;
    return 0;
}