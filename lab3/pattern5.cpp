#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    int x = 10,i=0, de=n;
    while (i<n)
    {   
        int s = 0;
        while(s<i)
        {
            cout<<"  ";
            s++;
        }
        int j = 0;
        while (j < n-i)
        {
            //for space
            // for number
            cout<<x<<" ";
            x = x + 2;
            j++;
        }
        cout<<endl;
        i++;
    }
    
    return 0;
}
