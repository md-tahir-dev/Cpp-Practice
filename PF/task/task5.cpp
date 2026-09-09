/*
 Write a program that finds the sum of the squares of integers from 1 to n. Where n is a
positive value entered by the user, also display the series.
 i.e., 12
 + 22
 + 32
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int value;
    cout<<"Enter the postive value n: ";
    cin>>value;
    int n = value;
    int result = 0;
    int power = 2;
    if(value<=0)
    {
        cout<<"Re-enter the postive value";
        return -1;
    }
    else{
    for(int i = 1; i<=n; i++)
    {
        int square = i*i;
        result += square;
        // cout<<result;
        cout<<i<<"^2 ";
        if(i<n){
            cout<<"+ ";
        }
    }
    // cout<<endl;
    cout<<"= "<<result;
    }
    return 0;
}