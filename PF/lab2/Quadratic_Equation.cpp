#include <iostream>
#include<cmath>
using namespace std;
void calculatedet(float a, float b, float c)
{
    float det=pow(b,2)-(4*(a*c));
    if(det<=0)
    {
        cout<<"re-enter";
        return;
    }
    float x1 = (-b + sqrt(det)) / (2 * a);
    float x2 = (-b - sqrt(det)) / (2 * a);
    cout<<"Determinant 1 is: "<<x1<<endl;
    cout<<"Determinant 2 is: "<<x2<<endl;
}
int main()
{
    float a,b,c;
    cout<<"Enter the value of a: ";
    cin>>a;
    if(a==0)
    {
        cout<<"Re-enter value! you cann't enter a = 0";
        return 0;
    }
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<"Enter the value of c: ";
    cin>>c;
    calculatedet(a,b,c);
    return 0;
}