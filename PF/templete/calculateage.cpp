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
    int cuuerentyear = 2026;
    int currentmonth = 8;
    int currentdate = 20;

    long countyears = cuuerentyear-brithyear;
    long countmonths = currentmonth-integerbrithmonth;
    long countdays = currentdate-brithdate;


    cout<<"Current month is: "<<countmonths<<endl;

    if(countdays<0)
    {
        countdays+=30;
        countmonths--;
    }

    if(countmonths<0)
    {
        countmonths+= 12;
        countyears--;
    }

    long countmonth=(countyears*12)+countmonths;
    long countday=(countyears*365)+(countmonths*30)+countdays;
    long countweeks= countday/7;
    long counthour = countday*24;
    long countmins= counthour*60;
    long countseconds = countmins*60;

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
//C==