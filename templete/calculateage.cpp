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
void calculateageindays(size_t brithdate,size_t brithyear, int integerbrithmonth)
{
    size_t cuuerentyear = 2026;
    size_t currentmonth = 8;
    size_t currentdate = 20;
    size_t countyears = cuuerentyear-brithyear;
    size_t countmonths = currentmonth-integerbrithmonth;
    if(countmonths<0)
    {
        countmonths+= 12;
        countyears--;
    }
    size_t countdays = currentdate-brithdate;
    if(countdays<0)
    {
        countdays+=30;
        countmonths--;
    }
    size_t countmonth=(countyears*12)+countmonths;
    size_t countday=(countyears*365)+(countmonths*30)+countdays;
    size_t countweeks= countday/7;
    size_t counthour = countday*24;
    size_t countmins= counthour*60;
    size_t countseconds = countmins*60;
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
    size_t brithdate,brithyear;
    string brithmonth;
    cout<<"Enter your brith year: ";
    cin>>brithyear;
    cout<<endl;
    cout<<"Enter your brith month (January to December): ";
    cin>>brithmonth;
    cout<<endl;
    size_t integerbrithmonth = brithmonthinnumber(brithmonth);
    cout<<"Enter your brith date: ";
    cin>>brithdate;
    cout<<endl;
    cout<<brithyear<<" / "<<brithmonth<<" / "<<brithdate<<endl;
    cout<<brithyear<<" / "<<integerbrithmonth<<" / "<<brithdate<<endl;
    calculateageindays(brithdate,brithyear,integerbrithmonth);
    return 0;
}