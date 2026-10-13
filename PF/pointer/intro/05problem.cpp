#include <iostream>
using namespace std;
void display(const int* pVal){
    cout<<pVal<<"   "<<*pVal<<endl;
    cout<<"in function pointer address: "<<&pVal<<endl;
    pVal=nullptr;
    // *pVal=10;
    cout<<"After changing into 'nullptr'."<<*(pVal)<<endl;
}

void dislayArray(const int *a,int n)
{
    for (int i = 0; i <n; i++)
    {
        cout<<*(a+i)<<"    "<<a+i<<endl;
        // a[i]=0; after const keyword we can't edit it.
    }
    
}

void getInput(int * p)
{
    cout<<"Enter an integer: ";
    cin>>*p;
}


int main()
{
    const int N = 5;
    int arr[N] = {11, 22, 33, 44, 55};
    int num = 54;
    int *p1 = &num;

    // cout<<num << "  "<<*(p1)<<endl;
    // cout<<"in main pointer address: "<<&p1<<endl;
    // display(p1);

    // cout<<"In main num is: "<<num<<endl;
    dislayArray(arr,N);

    int val;
    getInput(&val);
    cout<<"Value of val: "<<val<<endl;
    return 0;
}