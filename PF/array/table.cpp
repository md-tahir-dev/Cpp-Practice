#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    int stop;
    cout<<"On which number you want to stop table: ";
    cin>>stop;
    for (int i = 1; i <= stop; i++)
    {
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
    }
    
}