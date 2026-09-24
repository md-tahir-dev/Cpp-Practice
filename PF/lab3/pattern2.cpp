#include <iostream>

using namespace std;

int main()
{   
    int n; 
    cout<<"Enter number: ";
    cin>>n;    
    int a=0;
    int i = 1;
    while (a<n)
    {
        int b = 0;
        while (b<a+1)
        {
            cout<<i<<" ";
            i=i+2;
            b++;
        }
        cout<<endl;
        a++;
    }

    return 0;
}