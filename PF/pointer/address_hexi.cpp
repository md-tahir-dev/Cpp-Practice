#include<iostream>
using namespace std;
int main()
{
    int a = 10; 
    // int* ptr = &a;
    // cout<<"Address of a in memory: "<<ptr<<endl;
    // float price = 99.99;
    // float* price_ADDRESS = &price;
    // cout<<"Address of price: "<<price_ADDRESS<<endl;
    int *ptr = &a;
    cout<<ptr;
    cout<<endl;
    // int **ptr2 = &ptr;
    // cout<<ptr2;
    cout<<*(&a);
    cout<<endl;
    cout<<*(ptr)<<endl;
    int **pttr = NULL;
    cout<<pttr<<endl;
    
    return 0;
}