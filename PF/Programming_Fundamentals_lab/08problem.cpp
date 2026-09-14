// Write a program using a loop to calculate: S = 1^2 + 2^2 + 3^2 + ... + n^2, where n is entered by the user
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    for (size_t i = 1; i <=n; i++)
    {
        sum+=pow(i,2);
    }
    cout<<"Sum is "<<sum;
    return 0;
}