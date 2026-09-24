#include<iostream>
#include<climits>
using namespace std;
void smallest(int n)
{
    int int_min= INT_MIN;
    while (true)
    {
        cin>>n; 
        if(n==0)
        {
            break;
        }
        if(n>int_min)
        {
            int_min=n;
        }
    }
    if(int_min==INT_MIN)
    {
        cout<<"No number entered.";
    }
    else
    {
        cout<<"Max number is: "<<int_min;
    }
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    smallest(n);
    return 1;
}