//  Find Minimin of Three Number
#include <iostream>
using namespace std;
void  Find_Minimin(int val1, int val2, int val3)
{
    if(val1<val2&&val1<val3)
    {
        cout<<"First is Smaller";
    }
    else if(val2<val1&&val2<val3) 
    {
        cout<<"Second is Smaller";
    }
    else
    {
        cout<<"Third is Smaller";
    }
} 
int main()
{
    int val1,val2,val3;
    cout<<"Enter first value: ";
    cin>>val1;
    cout<<"Enter second value: ";
    cin>>val2;
    cout<<"Enter third value: ";
    cin>>val3;
    Find_Minimin(val1,val2,val3);
    return 0;
}