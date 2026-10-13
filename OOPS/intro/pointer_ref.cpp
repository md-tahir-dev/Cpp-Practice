#include <iostream>
using namespace std;
void deallocation(int *&p)
{
    delete p;
    p = nullptr;
}
int main()
{
    int *ptr = new int;
    *ptr = 40;
    cout << *ptr << endl;
    deallocation(ptr);
    if (ptr == nullptr)
    {
        cout << "ptr is NULL\n";
    }
    else
    {
        cout << "ptr is NOT NULL\n";
    }
    return 0;
}