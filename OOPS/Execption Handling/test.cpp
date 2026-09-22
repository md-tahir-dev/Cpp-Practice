#include <iostream>

using namespace std;

int main()
{
    try
    {
        cout << "A" << endl;
        throw 10;
        cout << "B" << endl;
    }
    catch (int x)
    {
        cout << "Exception: " << x << endl;
    }
    return 0;
}