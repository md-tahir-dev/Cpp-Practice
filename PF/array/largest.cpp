#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int num[]{15,8,10,-8,36,32};
    int size=sizeof(num)/sizeof(int);
    int large = INT_MIN;
    int small = INT_MAX;
    int indexSMALL = -1;
    int indexLARGE = -1;

    for(int i=0; i<size; i++){
        if(num[i]>large)
        {
            large=num[i];
            indexLARGE=i;
        }
        if(num[i]<small)
        {
            small=num[i];
            indexSMALL=i;
        }
        // large = max(num[i], large);
        // small = min(num[i], small);
    }
    // cout<<large[1];
    // cout<<large<<endl;
    // cout<<small;
    cout<<"postion of array is "<<indexLARGE<<endl;
    cout<<"postion of array is "<<indexSMALL<<endl;

    return 0;
}