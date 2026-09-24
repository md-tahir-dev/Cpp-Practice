#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    int i = 0;
    while (i<n)
    {
        int j = 0;
        while (j<= n-1-i)
        {
            cout<<"*  ";
            j++;
        }
        cout<<endl;
        i++;
    }
    int a=0;
    while (a<n)
    {
        int b = 0;
        while (b<=a)
        {
            cout<<"*  ";
            b++;
        }
        cout<<endl;
        a++;
    }
    
    
    
    return 0;
}