/*
Write a C++ program that takes two integer values, HIGH and LOW, from the user. If necessary, 
interchange the values so that the lower value comes first. Then calculate and display the sum 
of all even numbers between the two values, excluding the boundary values.
*/
#include <iostream>
using namespace std;
void find_sum_even(int first, int second)
{
    int sum=0;
    first=first+1;
    while (first<second)
    {
        if(first%2==0)
        {
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
    find_sum_even(first,second);
    return 0;
}