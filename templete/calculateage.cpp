#include <iostream>
using namespace std;
int brithmonthinnumber(string brithmonth)
{
    if(brithmonth=="January")
    {
        return 1;
    }
    else if(brithmonth=="February")
    {
        return 2;
    }
    else if(brithmonth=="March")
    {
        return 3;
    }
    else if(brithmonth=="April")
    {
        return 4;
    }
    else if(brithmonth=="May")
    {
        return 5;
    }
    else if(brithmonth=="June")
    {
        return 6;
    }
    else if(brithmonth=="July")
    {
        return 7;
    }
    else if(brithmonth=="August")
    {
        return 8;
    }
    else if(brithmonth=="September")
    {
        return 9;
    }
    else if(brithmonth=="October")
    {
        return 10;
    }
    else if(brithmonth=="November")
    {
        return 11;
    }
    else if(brithmonth=="December")
    {
        return 12;
    }
    else
    {
        cout<<"Enter months from (January to December)";
        return -1;
    }
}
void calculateageindays(int brithdate,int brithyear, int integerbrithmonth)
{
    int cuuerentyear = 2026;
    int currentmonth = 8;
    int currentdate = 20;
    int countyears = cuuerentyear-brithyear;
    int countmonths = currentmonth-integerbrithmonth;
    if(countmonths<0)
    {
        countmonths+= 12;
        countyears--;
    }
    int countdays = currentdate-brithdate;
    if(countdays<0)
    {
        countdays+=30;
        countmonths--;
    }
    int countmonth=(countyears*12)+countmonths;
    int countday=(countyears*365)+(countmonths*30)+countdays;
    int countweeks= countday/7;
    int counthour = countday*24;
    int countmins= counthour*60;
    int countseconds = countmins*60;
    // month
    cout<<"Year: "<<countyears<<" Months: "<<countmonths<<" Days: "<<countdays<<endl;
    cout<<"Your Total Months: "<<countmonth<<endl;
    cout<<"Your Total weeks: "<<countweeks<<endl;
    cout<<"Your Total days: "<<countday<<endl;
    cout<<"Your Total hours: "<<counthour<<endl;
    cout<<"Your Total mins: "<<countmins<<endl;
    cout<<"Your Total seconds: "<<countseconds<<endl;
}
int main()
{
    int brithdate,brithyear;
    string brithmonth;
    cout<<"Enter your brith year: ";
    cin>>brithyear;
    cout<<endl;
    cout<<"Enter your brith month (January to December): ";
    cin>>brithmonth;
    cout<<endl;
    int integerbrithmonth = brithmonthinnumber(brithmonth);
    cout<<"Enter your brith date: ";
    cin>>brithdate;
    cout<<endl;
    cout<<brithyear<<" / "<<brithmonth<<" / "<<brithdate<<endl;
    cout<<brithyear<<" / "<<integerbrithmonth<<" / "<<brithdate<<endl;
    calculateageindays(brithdate,brithyear,integerbrithmonth);
    return 0;
}