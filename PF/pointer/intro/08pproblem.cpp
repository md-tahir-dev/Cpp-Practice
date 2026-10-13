#include <iostream>
using namespace std;
int main()
{
    int* ptr1= new int;
    int *ptr2= new int;
    *ptr1=10;
    *ptr2=35;
    cout<<*ptr1<<"  "<<*ptr2<<endl;
    
    // delete ptr1;//destorying ptr1
    // ptr1=nullptr;

    int * ptr3 = ptr1;

    ptr1=ptr2;
    
    cout<<*ptr1<<"  "<<*ptr2<<endl;
    cout<<*ptr3<<"  "<<*ptr2<<endl;
    
    ptr1=ptr3;
    
    cout<<*ptr1<<"  "<<*ptr2<<endl;
    
    *ptr2=*ptr1;
    cout<<*ptr1<<"  "<<*ptr2<<endl;

    delete ptr3;
    ptr3=nullptr;
    
    delete ptr2;
    ptr2=nullptr;

    return 0;
}