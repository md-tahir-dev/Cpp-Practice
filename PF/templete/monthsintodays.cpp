#include <iostream>
using namespace std;
void monthsintodays(int months,int week,int day)
{
    int countdays=0;
    countdays += months*30;
    countdays += week*7;
    countdays += day;
    cout<<"Total days are: "<<countdays;
}
int main()
{
    int day,week, months;
    cout<<"Enter months: ";
    cin>>months;
    cout<<endl;
    cout<<"Enter weeks: ";
    cin>>week;
    cout<<endl;
    cout<<"Enter days: ";
    cin>>day;
    cout<<endl;
    monthsintodays(months,week,day);
    return 0;
}