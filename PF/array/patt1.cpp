#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    char symbol = '*';
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            cout<<" ";
        }
        for(int x = 4; x>i-1;x--)
        {
            cout<<symbol;
        }
        cout<<endl;
    }
}