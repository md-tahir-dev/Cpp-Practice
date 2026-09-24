#include <iostream>

using namespace std;
void daytomnths(int days)
{
    int months, weeks, day;
    months=days/30;
    cout<<"Months: "<<months<<" ";
    int countday=days%30;
    weeks=countday/7;
    cout<<"Weeks: "<<weeks<<" ";
    day=countday%7;
    cout<<"Days: "<<day;
}
int main()
{
    int days;
    cout<<"Enter days: ";
    cin>>days;
    if(days<0)
    {
        cout<<"Days should be positive: ";
        return -1;
    }    
    daytomnths(days);
    return 0;
}