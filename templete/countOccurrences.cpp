#include <iostream>

using namespace std;
template <typename T>
auto countOccurrences(T arr[], size_t size, T target)
{
    int count=0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i]==target)
        {
            count++;
        }
    }
    return count;
    
}
int main()
{
    int arr[]={10, 20, 10, 30, 10, 40};
    int target = 10;
    size_t size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Integer Output: "<<countOccurrences(arr,size,target)<<endl;
    char chararr[]={'A', 'B', 'C', 'A', 'D', 'A'};
    char chartarget = 'A';
    size_t charsize = sizeof(chararr)/sizeof(chararr[0]);
    cout<<"Character Output: "<<countOccurrences(chararr,charsize,chartarget)<<endl;
    float floatarr[]={2.5f, 7.8f, 2.5f, 9.6f, 5.6f, 2.5f};
    float floattarget = 2.5;
    size_t floatsize = sizeof(floatarr)/sizeof(floatarr[0]);
    cout<<"Float Output: "<<countOccurrences(floatarr,floatsize,floattarget)<<endl;

    return 0;
}