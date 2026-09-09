#include <iostream>

using namespace std;
template <typename T>
T square(T x)
{
    return x * x;
}
int main()
{
    cout<<"The Square is: "<<square(2)<<endl;
    cout<<"The Square is: "<<square(9.1)<<endl;
    return 0;
}