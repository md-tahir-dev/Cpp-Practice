#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a="abc";
    string b="xyz";
    string temp=a;
    a=b;
    b=temp;
    cout<<"Value of a is "<<a<<endl;
    cout<<"Value of b is "<<b<<endl;
    return 0;
}