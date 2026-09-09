#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b)
{
    if (a > b)
        return a;

    return b;
}

int main()
{
    cout << maximum(10, 20) << endl;

    cout << maximum(3.5, 2.1) << endl;

    cout << maximum('A', 'Z') << endl;

    return 0;
}