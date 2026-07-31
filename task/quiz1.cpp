#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a postive integer: ";
    cin>>n;
    for(int i = 0; i<40;i++)
    {   if(n<3)
        {
            cout<<n;
            break;
            cout<<endl;
        }
        if(n%2==0&&n<10)
        {
            cout<<n<< "(even and less than 10, multiply by 5) ->";
            cout<<endl;
            n = n * 5;
        }
        // cout<<n;
        else if (n%2==0&&n>=10)
        {
            cout<<n<< "(even and greater than 10, divide by 2) ->";
            cout<<endl;
            n = n / 2;
        }
        else if (n%2!=0)
        {
            cout<<n<< "(old, multiply by 3 and add by 1) ->";
            cout<<endl;
            n = n * 3;
            n = n + 1;
            // cout<<n;
        }
            // cout<<n;
        
    }
}