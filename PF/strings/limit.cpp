#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
    char str[15];
    cout<<"Enter name: ";
    cin.getline(str,15,'!');
    cout<<str;

}