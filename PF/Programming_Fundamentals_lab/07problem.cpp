// Write a program using nested loops to print the following pattern:
// *
// * *
// * * *
// * * * *
// * * * * *

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < i+1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}