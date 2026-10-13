#include <iostream>

using namespace std;

int main()
{
    int num=15;
    int * ptr1 = &num;
    cout<<num<<"    "<<*ptr1<<endl;

    int ** address = &ptr1;
    cout<<ptr1<<"    "<<*address<<endl;
    
    **address += 10; 
    cout<<num<<"    "<<*ptr1<<"     "<<**address<<endl;

    delete ptr1;
    ptr1=nullptr;
    address=nullptr;
    
    // cin>>num;
    // cin>>*ptr1;
    // int * ptr = new int;
    // *ptr = 20;
    // cout<<*ptr<<endl;
    // delete ptr;
    // ptr = nullptr;
    return 0;
}