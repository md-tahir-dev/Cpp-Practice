#include<iostream>
using namespace std;
int main()
{
    char c ='a';
    if(c>='a'&&c<='z')
    {
        c=c-32;
        cout<<c;
    }
}