#include <iostream>
using namespace std;

int main()
{
    int var = 10;
    int* pt;
    pt = &var;

    cout << "The address is : " << pt << endl;  //0x61ff08
    
    // We get value by dereferencing
    cout << "Updated value is " << *pt << endl; //10
    
    // Update value using dereferencing
    *pt = 20;
    cout << "Further updated value is " << var << endl;     //20
    
    var = 30;
    
    // Access new updated value using
    // dereferncing
    cout << "The value is " << *pt << endl;     //30
}