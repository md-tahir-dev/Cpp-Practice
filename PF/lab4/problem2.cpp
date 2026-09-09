#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    if(n%2==0||n<2)
    {
        cout<<"Invaild.";
        return 0;
    }
    int mid = n / 2;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==mid||j==mid||i==j||i+j==n-1)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}