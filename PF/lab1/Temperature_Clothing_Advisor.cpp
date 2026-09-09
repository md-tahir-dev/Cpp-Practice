/*
Temperature Clothing Advisor:
Write a program that suggests what to wear based on temperature:
• If temperature is above 30°C: "Wear light clothes"
• If temperature is between 20°C and 30°C: "Wear a t-shirt"
• If temperature is between 10°C and 20°C: "Bring a jacket"
• If temperature is below 10°C: "Wear warm clothes"
*/

#include <iostream>
using namespace std;
void Clothing_Advisor(size_t temp)
{
    if(temp>30)
    {
        cout<<"Wear light clothes";
    }
    else if(temp>=20&&temp<=30)
    {
        cout<<"Wear a t-shirt";
    }
    else if(temp>=10&&temp<20)
    {
        cout<<"Bring a jacket";
    }
    else 
    {
        cout<<"Wear warm clothes";
    }
}
int main()
{
    size_t temp;
    cout<<"Enter temp: ";
    cin>>temp;
    Clothing_Advisor(temp);
    return 0;
}