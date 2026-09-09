#include<iostream>
using namespace std;

int isEven(int num)
{   
    int num;
    bool even= "ture";
    if(num%2==0){
        cout<<even;
    }
    else{
        even=false;
        cout<<even;
    }
    return even;
}

int main()
{   
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    isEven();
    cout<<isEven();
    return 0;
}