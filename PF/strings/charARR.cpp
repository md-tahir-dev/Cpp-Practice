#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char arr[]={'a','b','c','d','e','\0'};
    char str[]="Muhammad";
    // for(char ch:arr)
    // {
    //     cout<<ch<<" ";
    // }
    cout<<strlen(arr)<<endl;
    cout<<arr<<endl;
    cout<<strlen(str)<<endl;
    cout<<str<<endl;
}