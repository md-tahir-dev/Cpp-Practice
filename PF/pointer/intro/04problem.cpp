#include <iostream>

using namespace std;

int main()
{
    const int N = 5;
    int arr[N]={11,22,33,44,55};
    // int * ptr = arr;
    int * pStart=nullptr,*pEnd=nullptr;
    pStart=&arr[0];
    pEnd=&arr[N-1];
    // cout<< pEnd-pStart<<endl;//4

    while (pStart<=pEnd)    //pointer comperi
    {
        cout<<*pStart<<"    ";
        pStart++;
    }
    
    // cout<< pEnd+pStart<<endl;// ERROR
    // for (int i = 0; i < N; i++)
    // {
    //     cout<<ptr<<"    "<<*ptr<<endl;
    //     ptr+=1 ;//pointer arithmetic
    //     // ptr++;
    //     // ptr=ptr+1
    //     // ++ptr;
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     ptr-=1;
    //     cout<<ptr<<"    "<<*ptr<<endl;
    // }
    return 0;
}