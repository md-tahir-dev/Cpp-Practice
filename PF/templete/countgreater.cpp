#include <iostream>

using namespace std;
template <typename T>
size_t countGreater(T arr[], size_t size, T &target)
{
    int count=0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i]>target)
        {
            count++;
        }

    }
    return count;
}
int main()
{
    int intarr[]={10 ,20, 30 ,40};
    size_t size = sizeof(intarr)/sizeof(intarr[0]);
    int target = 20;
    cout<<"Output: ";
    cout<<countGreater(intarr,size,target)<<endl;
    double doublearr[]={1.1, 2.2, 3.3, 4.4};
    size_t sized = sizeof(doublearr)/sizeof(doublearr[0]);
    double dtarget = 2.2;
    cout<<"Double Output: "<<countGreater(doublearr,sized,dtarget)<<endl;

    float floatarr[]={1.5f, 2.5f, 3.5f, 4.5f};
    size_t sizef = sizeof(floatarr)/sizeof(floatarr[0]);
    float ftarget = 2.5f;
    cout<<"Float Output: "<<countGreater(floatarr,sizef,ftarget)<<endl;

    return 0;
}