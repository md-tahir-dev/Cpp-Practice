#include <iostream>
using namespace std;
void convertSeconds(int second)
{
    int hour,mins,seconds;
    hour=second/3600;
    cout<<"Hour: "<<hour<<" ";
    // int forseconds=second%3600;
    mins=second%3600;
    int formins=mins/60;
    cout<<"mins: "<<formins<<" ";
    seconds=mins%60;
    cout<<"second: "<<seconds;
    // second

}
int main()
{
    int second;
    cout<<"Enter seconds: ";
    cin>>second;
    if(second<0)
    {
        cout<<"Second should be positive: ";
        return -1;
    }
    convertSeconds(second);
    return 0;
}