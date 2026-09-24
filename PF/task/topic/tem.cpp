#include<iostream>
using namespace std;
int main()
{
    float fahrenheit;
    cout<<"Enter fahrenheit: ";
    cin>>fahrenheit;
    float celsius = (fahrenheit-32)*5/9;
    cout<<"celsius is "<<celsius;
}