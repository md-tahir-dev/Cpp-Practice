#include<iostream>
using namespace std;
void DP(float a,float b, float c)
{
    float result1=a*(b+c);
    float result2=(a*b)+(a*c);
    if(result1!=result2)
    {
        cout<<"not distributive property.";
        return;
    }
    else
    {
        cout<<"distributive property";
    }
}
int main()
{
    float a,b,c;
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<"Enter the value of c: ";
    cin>>c;
    DP(a,b,c);
    return 0;
}