#include <iostream>

using namespace std;
template <typename T>
T findMax(T a, T b, T c)
{
    if(a>b && a>c)
    {
        return a;
    }
    else if (b>a&&b>c)
    {
        return b;
    }
    else
    {
        return c;
    }
    
}
int main()
{
    cout << findMax(10, 25, 15) << endl;
    cout << findMax(2.5, 8.7, 4.1) << endl;
    cout << findMax(3.2f, 1.5f, 9.8f) << endl;

    return 0;
}