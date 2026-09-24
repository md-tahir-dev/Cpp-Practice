#include <iostream>
using namespace std;

void greet()
{
    cout << "Hello!";
}

int main()
{
    void (*fp)();

    fp = &greet;

    cout << "Address stored in fp: " << fp << endl;
    cout << "Address of fp itself: " << &fp << endl;

    fp();
}