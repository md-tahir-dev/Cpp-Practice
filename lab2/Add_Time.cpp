#include <iostream>
using namespace std;
void calculatetime(size_t currhour,size_t currmin,size_t currsec,size_t addhour, size_t addmin, size_t addsec)
{
    size_t total_sec = currsec + addsec;
    size_t carry_min = total_sec / 60;
    size_t final_sec = total_sec % 60;
    
    size_t total_min = currmin +  addmin + carry_min;
    size_t carry_hour = total_min/60;
    size_t final_min = total_min%60;

    size_t final_hour = (currhour+addhour+carry_hour)%24;

    cout<<"Your  time after add: "<<final_hour<<" : "<<final_min<<" : "<<final_sec;
}
int main()
{
    size_t currhour,currmin, currsec;
    cout<<"Enter current hours: ";
    cin>>currhour;
    cout<<"Enter current min: ";
    cin>>currmin;
    cout<<"Enter current second: ";
    cin>>currsec;

    size_t addhour, addmin, addsec;
    cout<<"Enter hours that want to add: ";
    cin>>addhour;
    cout<<"Enter min that want to add: ";
    cin>>addmin;
    cout<<"Enter second that want to add: ";
    cin>>addsec;
    calculatetime(currhour,currmin,currsec,addhour,addmin,addsec);
    return 0;
}