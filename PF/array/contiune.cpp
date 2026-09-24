#include<iostream>
using namespace std;
int main()
{
    int nums = 1, n = 5;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<i+1; j++)
        {
            cout<<nums<<" ";
            nums++;
        }
        cout<<endl;
    }
}