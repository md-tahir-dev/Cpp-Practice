#include<iostream>
using namespace std;
// function defination
int hello()
{
    // cout<<"Hello"<<endl;
    return 10;
}
void squarenum()
{   
    int n;
    cout<<"You Entered: ";
    cin>>n;
    cout << "Your entered value square is: " << n*n << endl;
}

int sum(int a, int b)
{ 
    cout<<"Enter a value of a: ";
    cin>>a;
    cout<<"Enter a value of b: ";
    cin>>b;
    int sum=a+b;
    cout<<"Sum of a and b is: "<<sum;
}
int main()
{   
    // int hello_value = hello();
    // cout<<hello_value<<endl;
    // cout<<"Enter num: ";
    // cin>>n;
    squarenum();
    cout<<endl;
    sum(1,2);
    return 0;
}



/*
function-type function-name(arguments)
{
    block of statment   
} 
*/