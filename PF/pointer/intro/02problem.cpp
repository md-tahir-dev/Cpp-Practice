#include <iostream>

using namespace std;

int main()
{
    // char arr[4]={'a','b','c','d'};
    short arr[4]={1,2,3,4};
    short * sp = arr;
    cout<<"Base address of array: "<<arr<<endl;
    for (size_t i = 0; i < 4; i++)
    {
        sp = &arr[i];
        cout<<"Element # " << i << " " <<&sp[i]<<"     "<<arr[i]<<endl;
    }
    cout<<endl;
    return 0;
}