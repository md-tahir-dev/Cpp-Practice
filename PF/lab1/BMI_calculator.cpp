/*Take input from the user (height and weight) and make a BMI calculator for the fitness center.
BMI=(Height in m) / (Weight in kg)*/
#include <iostream>
using namespace std;
float BMI(float height, float weight)
{
    float douheight=height*height;
    float bmical=weight/douheight;
    return bmical;
}
int main()
{
    float height,weight;
    cout<<"Enter your height in meter: ";
    cin>>height;
    if(height<=0)
    {
        cout<<"Re-enter height";
        return 0;
    }
    cout<<endl<<"Enter your weight in kg: ";
    cin>>weight;
    if(weight<=0)
    {
        cout<<"Re-enter weight";
        return 0;
    }    
    cout<<"BMI: "<<BMI(height,weight);
    return 0;
}