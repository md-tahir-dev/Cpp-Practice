#include <iostream>
using namespace std;
void Time(int second)
{
    int hours, min, sec;
    hours=second/3600;
    min =(second%3600)/60;
    sec = second%60;
    cout<<hours<<" hr, "<<min<<" min and "<<sec<<" sec";
}
int main()
{
    size_t second;
    cout<<"Enter second: ";
    cin>>second;
    Time(second);
    return 0;
}