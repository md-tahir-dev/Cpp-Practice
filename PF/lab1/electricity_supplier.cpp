/*
An electricity supplier company charges electricity bills based on the following conditions:
• Up to 100 units → 5 per unit
• 101 - 300 units → 8 per unit
• Above 300 units → 10 per unit
You have to input the total number of units consumed and calculate the total bill or total cost of 
electricity.

*/
#include <iostream>
using namespace std;
int unit_cal(int unit)
{
    if(unit<=100)
    {
        return unit*5;
    }
    else if(unit>100||unit<=300)
    {
        return unit*8;
    }
    else
    {
        return unit * 10;
    }
}
int main()
{
    int unit;
    cout<<"Enter unit: ";
    cin>>unit;
    cout<<"Your bill is: "<<unit_cal(unit);
    return 0;
}