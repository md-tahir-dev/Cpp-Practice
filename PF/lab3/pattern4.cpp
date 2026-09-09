#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    cout<<"Enter number: ";
    cin>>n;
    int i = 0; 
    while (i<n)
    {
        int s=0;
        while (s < n-i-1 )
        {
            cout<<"  ";
            s++;
        }
        int in=i+1;
        while (in<=i+1+i)
        {
            cout<<in<<" ";
            in++;
        }
        int de = i + 1;
        while (de >= i+1)
        {
            cout<<de<<" ";
            de--;
        }

        cout<<endl;
        i++;
    }
    
    return 0;
}