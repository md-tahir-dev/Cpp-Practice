#include<iostream>
using namespace std;
int main()
{
    int num;
    int fact=1;
    cout<<"Enter a number: ";
    cin>>num;
    if(num>1)   
        {
            while (num>1)
            {
                fact = fact * num;
                num--;
            }
            cout<<"Fact is: "<<fact;
            
        }
    else{
        cout<<"Re-enter";
    }
}