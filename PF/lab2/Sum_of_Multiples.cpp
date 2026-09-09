/*
Program Statement: Write a C program that takes a high and low integer value from the user. Arrange
the values so that the lower value comes first, then calculate and display the sum of all numbers that are
multiples of 3 between the two values, excluding the boundary values.
Concepts Used: while loop, % operator, accumulator variable, conditional statemen
*/

#include <iostream>
using namespace std;
void sum(int first, int second)
{
    int sum = 0;
    while (first<second)
    {
        if(first%3==0)
        {
            cout<<first<<endl;
            sum+=first;
        }
        first++;
    }
    cout<<"Sum is: "<<sum;
}
int main()
{
    int first, second;
    cout<<"Enter first limit: ";
    cin>>first;
    cout<<"Enter second limit: ";
    cin>>second;
    if(first>second)
    {
        int temp = first;
        first = second;
        second = temp;
    }   
    sum(first,second);
    return 0;
}