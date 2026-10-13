#include <iostream>

using namespace std;
int * getValue(){
    // int num;
    int * temp= new int;
    cout<<"Enter a value: ";
    cin>>*temp;
    cout<<"In function, address of num: "<<temp<<endl;
    return temp;
}
int main()
{
    int * ptr;
    
    ptr = getValue();
    cout<<"Pointer is: "<<ptr<<endl;
    cout<<"You entered: "<<*ptr<<endl;
    delete ptr;
    ptr  = nullptr;
    cout << "After nullptr ptr value: "<<ptr<<endl;
    return 0;
}