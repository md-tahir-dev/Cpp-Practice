/*
 Write a program that gets two numbers from the user and displays the result of first
number raised to the power of second number using do-while loop
Enter a base number: 3
Enter a Exponet number: 5
The Result is : 243
*/
#include <iostream>
using namespace std;
int main()
{
    int base, power, result=1;
    cout<<"Enter a base number: ";
    cin>>base;
    cout<<"Enter a power value: ";
    cin>>power;
    int i = 0;
    if(power==0)
    {
        cout<<"Power can't be zero";
        return 0;
    }
    do{
        result = result*base;
        i++;
    }
    while(i<power);
    cout<<"The result is: "<<result;
}