#include <iostream>
#include<string>
using namespace std;


void calculatetime(size_t currhour,size_t currmin,size_t currsec, size_t addhour, size_t addmin, size_t addsec)
{
    size_t total_sec = currsec + addsec;
    size_t carry_min = total_sec / 60;
    size_t final_sec = total_sec % 60;

    size_t total_min = currmin + addmin + carry_min;
    size_t carry_hour = total_min / 60;
    size_t final_min = total_min % 60;

    size_t total_hour = currhour + addhour + carry_hour;
    size_t final_hour = total_hour % 24;

    if (currhour == 0)
    {
        cout << 12 << " : " << currmin << " : " << currsec << " AM";
    }
    else if (currhour < 12)
    {
        cout << currhour << " : " << currmin << " : " << currsec << " AM";
    }
    else if (currhour == 12)
    {
        cout << 12 << " : " << currmin << " : " << currsec << " PM";
    }
    else
    {
        cout << currhour - 12 << " : " << currmin << " : " << currsec << " PM";
    }
}

int main()
{
    size_t currhour, currmin, currsec;
    cout << "Enter current hours : ";
    cin >> currhour;
    cout << "Enter current min: ";
    cin >> currmin;
    cout << "Enter current second: ";
    cin >> currsec;

    size_t addhour, addmin, addsec;
    cout << "Enter hours that want to add: ";
    cin >> addhour;
    cout << "Enter min that want to add: ";
    cin >> addmin;
    cout << "Enter second that want to add: ";
    cin >> addsec;

    calculatetime(currhour, currmin, currsec, addhour, addmin, addsec);
    return 0;
}
