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
// int mod(int a, int b)
// {
//     return a%b;
// }
float divide(float a, float b)
{
     return a/b;
}

int main()
{   
    float a, b;
    float total;
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
        // cout<<sum(a,b)<<endl;
        total=sum(a,b);
        
    }
    // else if(op=='%')
    // {
    //     cout<<mod(a,b)<<endl;
    // }
    else if(op=='-')
    {
        total=sub(a,b);
        // cout<<sub(a,b)<<endl;
    }
    else if(op=='*')
    {
        total=multi(a,b);
        // cout<<multi(a,b)<<endl;
    }
    else if(op=='/')
    {
        if (b!=0)
        {
            total=divide(a,b);
            // cout<<divide(a,b)<<endl;
        } 
        else
        {
            cout << "Error! Division by zero is not allowed."<<endl;
            continue;
        }       
    }
    else{
        cout<<"Invaild Opreator you can use (+,-,*,/)"<<endl;
        continue;
        }
        a=total;
        cout<< a<<endl;
    }
    //after calculation total should store in variable "a"
    return 0;
}


// one variable total that will save total after every calculation
