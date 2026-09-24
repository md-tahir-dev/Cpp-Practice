#include <iostream>
#include<string>
using namespace std;

int main()
{
    // variable = (condition) ? expressionTrue : expressionFalse;
    int time = 20;
    // if (time < 18) 
    // {
    //   cout << "Good day.";
    // } 
    // else 
    // {
    //   cout << "Good evening.";
    // }
    cout<<( (time<18)?"Good day.": "Good evening.");

    int time = 22;
    string message = (time < 12) ? "Good morning."  //nested if else in terney
        : (time < 18) ? "Good afternoon."
        : "Good evening.";
    cout << message;
    return 0;
}