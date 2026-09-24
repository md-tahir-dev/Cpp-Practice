#include <iostream>
using namespace std;
float sum(float a, float b)
{
     return a+b;
}
float sub(float a, float b)
{
     return a-b;
}
float multi(float a, float b)
{
     return a*b;
}
float divide(float a, float b)
{
     return a/b;
}

int main()
{   
    float a, b;
    char op;
    cout<<"Enter first value: ";
    cin>>a;
    if(a==-1){
        cout<<"Exit";
        return 0;
    }
    // cout<<"Enter second value: ";
    // cin>>b;
    // cout<<"Enter operator: ";
    // cin>>op;
    while(true){
    cout<<"Enter second value: ";
    cin>>b;
    if(b==-1)
    {
        cout<<"Exit";
        return 0;
    }
    cout<<"Enter operator: ";
    cin>>op;

    if(op=='+')
    {
        cout<<sum(a,b);
    }
    else if(op=='-')
    {
        cout<<sub(a,b);
    }
    else if(op=='*')
    {
        cout<<multi(a,b);
    }
    else if(op=='/')
    {
        if (b!=0)
        {
            cout<<divide(a,b);
        } 
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }       
        
    }
    else{
        cout<<"Invaild Opreator you can use (+,-,*,/)";
    }
    }
    
    return 0;
}
