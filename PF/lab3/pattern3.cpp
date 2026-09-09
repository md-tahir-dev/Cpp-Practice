#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    int i = 0,a=0,x=0;
    while (i<n)
    {
        int j = 0;
        while (j< n-i)
        {
            cout<<"*";
            j++;
        }
        int k = 0;
        while (k<i+1)
        {
            cout<<" ";
            k++;
        }
        int b = 0;
        while (b <n-i)
        {
            cout<<"*";
            b++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
// want to print this
/*
***** *****
****  ****
***   ***
**    **
*     *
*/
        
