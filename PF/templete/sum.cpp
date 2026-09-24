#include <iostream>
using namespace std;
template <typename T> 
// this is templete
T add(T a, T b) 
{
    return a + b; 
}

int main()
{
    cout<<"The sum of a and b is: "<<add(2,2)<<endl;
    cout<<"The sum of a and b is: "<<add(2.2,2.9)<<endl;
    
    return 0;
}