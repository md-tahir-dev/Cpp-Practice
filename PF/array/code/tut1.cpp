#include<iostream>
using namespace std;

void proccessUntilSentinel(int *start)
{
    while (*start!=-1)
    {
        cout<<*start<<" ";
        start++;
    }
    
}
int main()
{
    int arr[]={5,12,8,24,-1};
    proccessUntilSentinel(arr);
    return 0;
}