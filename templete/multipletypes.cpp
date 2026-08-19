#include <iostream>

using namespace std;
template<typename T,typename U>
void print (T a, U b)
{
    cout << a << " " << b << endl;
}
template <typename T, typename U>
auto add(T a, U b)
{
    return a + b;
}
int main()
{
    print(2,2.5);
    cout<<"The sum of a and b is: "<<add(2,2.3)<<endl;
    return 0;
}