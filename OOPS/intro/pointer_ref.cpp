#include <iostream>
using namespace std;
void deallocate_int_ptr(int *& p)
{
    delete p;
    p = nullptr;
}
int main()
{
    int *ptr = new int;
    *ptr = 40;
    cout << *ptr << endl;
    deallocate_int_ptr(ptr);
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