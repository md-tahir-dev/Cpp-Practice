#include <iostream>
#include<string>
using namespace std;

string to12(size_t hour24) {
    string period = (hour24 < 12 ? "AM" : "PM");
    size_t hour12 = hour24 % 12;
    if (hour12 == 0) hour12 = 12;
    return to_string(hour12) + " " + period;
}

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

    cout << "Current time : "<< to12(currhour) << " : " << currmin << " : " << currsec << endl;

    cout << "Your time after add : "<< to12(final_hour) << " : "<< final_min << " : "<< final_sec << endl;
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
