#include <iostream>

using namespace std;
template <typename T>
T swapValues(T a,  T b)
{
    cout<<"Before: "<<a <<" "<<b<<endl;
    T temp;
    temp = a;
    a=b;
    b=temp;
    cout<<"After: "<<a <<" "<<b<<endl;
}

int main()
{
    swapValues(10,20);
    cout<<endl;
    swapValues(2.5,7.8);
    cout<<endl;
    swapValues('A','B');
    cout<<endl;
    return 0;
}