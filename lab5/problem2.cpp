#include<iostream>
#include<climits>
using namespace std;
void smallest(int n)
{
    int int_max= INT_MAX;
    while (true)
    {
        cin>>n; 
        if(n==0)
        {
            break;
        }
        if(n<int_max)
        {
            int_max=n;
        }
    }
    if(int_max==INT_MAX)
    {
        cout<<"No number entered.";
    }
    else
    {
        cout<<"Min number is: "<<int_max;
    }
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    smallest(n);
    return 1;
}