#include<iostream>
using namespace std;
int main() 
{
    char ch; 
    cout<<"Enter a Character: ";
    cin>>ch;
    if(ch>='A' && ch<='Z')
    {    
        cout<<"Upper";
    }
    else if(ch>='a' && ch<='z'){
        cout<<"Lower";
    }
    // if(ch>=65 && ch<=90) Inplicit conversion
    // {    
    //     cout<<"Upper";
    // }
    // else if(ch>=97 && ch<=123){
    //     cout<<"Lower";
    // } with ASCII Code   
    else{
        cout<<"Invaild";
    }
}

// Conversion of data type that is done by compiler it's called implicit conversion