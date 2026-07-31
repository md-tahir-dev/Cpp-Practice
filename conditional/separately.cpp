#include <iostream>
using namespace std;
int main ()
{
    int num, digit;
    cout << "Enter a number: ";
    cin >> num;
    digit = num % 10; 
    cout  << digit <<",";
    num = num / 10;
    digit = num % 10;
    cout  << digit <<",";
    num = num / 10;
    digit = num % 10;
    cout << digit <<",";
    num = num / 10;
    digit = num % 10;
    cout << digit;
}





























 // int a, b, c, d;
    // cout << "Enter the first number: ";
    // cin >> a;   
    // cout << "Enter the second number: ";
    // cin >> b;       
    // cout << "Enter the third number: ";     
    // cin >> c;
    // cout << "Enter the fourth number: ";
    // cin >> d;
    // cout<<a<<","<<b<<","<<c<<","<<d;
