/*
*         *
* *       * *
* * *     * * *
* * * *   * * * *
* * * * * * * * * * 
* * * *   * * * *
* * *     * * *  
* *       * *
*         *
*/
#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=i)
        {
            cout<<"* ";
            j++;
        }
        j=1;
        while (j <= 2*(n-i))
        {
            cout<<" ";
            j++;
        }
        j=1;
        while (j<=i)
        {
            cout<<"* ";
            j++;
        }
        cout<<endl;
        i++;
    }
    i=n-1;
    while (i>=1)
    {
        int j = 1;
        while (j<=i)
        {
            cout<<"* ";
            j++;
        }
        j=1;
        while (j <= 2*(n-i))
        {
            cout<<" ";
            j++;
        }
        j=1;
        while (j<=i)
        {
            cout<<"* ";
            j++;
        }
        cout<<endl;
        i--;
    }
    return 0;
}