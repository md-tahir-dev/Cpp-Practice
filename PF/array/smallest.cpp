#include<iostream>
#include <climits>
using namespace std;
int main()
{
    int num[]={36,10,-19,6,1,26};
    // cout<<sizeof(num)/sizeof(int);
    int size = 6;
    int small = INT_MAX;
    for(int i = 0; i<size; i++)
    {
        if(num[i]<small)
        small=num[i];
    }
        cout<<small;
    return 0;
}
