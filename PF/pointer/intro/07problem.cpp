#include <iostream>
using namespace std;
int main()
{
    int num ;//Stack
    int arr[10];//Stack
    int * ptr = nullptr;//Stack
    int * p1 = new int;//Heap
    *p1=21;
    cin>>*p1;
    cout<< *p1<< endl;
    delete p1;
    ptr= nullptr;

    return 0;
}