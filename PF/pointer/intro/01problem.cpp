#include <iostream>

using namespace std;

int main()
{
    // Pointer --> Address 
    // int num = 56;
    // cout<<"Variable num contains: "<<num<<endl;
    // cout<<"Size of num is: "<<sizeof(num)<<endl;
    // cout<<"Address of num is: "<<&num<<endl;
    // // const int N = 5;
    // // cout<<&N<<endl;
    // // cout<<&5<<endl;
    // int* address;
    // address=&num;
    // cout<<"Ptr contains: "<<address<<endl;
    
    double val=4.5;
    double*ptr=&val;
    double*ptr2=&val;
    cout<<"Variable val contains: "<<val<<endl;
    cout<<"Size of val is: "<<sizeof(val)<<endl;
    cout<<"Size of val pointer is: "<<sizeof(ptr)<<endl;
    cout<<"Address of val is: "<<&val<<endl;
    cout<<"Ptr contains: "<<ptr<<endl;  
    cout<<"Ptr address contains: "<<* ptr<<endl;  
    // cin>>*ptr;
    // cout<<"Variable val contains: "<<val<<endl;

    int y = val+5*5;
    int z = *ptr+5*5;
    cout << y << " " << z <<endl;
    cout<<"Ptr 2 "<<*ptr2<<endl;
    cout<<"Ptr 2 contains: "<<ptr2<<endl;
    cin>>*ptr2;
    cout<<"Ptr2 came: "<<val<<endl;
    // int *temp=nullptr;
    // cout<<temp<<endl;
    int *a = 0, *b = NULL, *c = nullptr, *d = nullptr;
    return 0;
}