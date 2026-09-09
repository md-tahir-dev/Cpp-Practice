#include <iostream>

using namespace std;
void hourintoseconds(int hour, int min, int second)
{
    int countseconds=0;
    countseconds+=hour*3600;
    countseconds+=min*60;
    countseconds+=second;
    cout<<"Total seconds are: "<<countseconds;
}
int main()
{
    int second,min, hour;
    cout<<"Enter hour: ";
    cin>>hour;
    cout<<endl;
    cout<<"Enter mins: ";
    cin>>min;
    cout<<endl;
    cout<<"Enter seconds: ";
    cin>>second;
    cout<<endl;
    hourintoseconds(hour,min,second);    
    return 0;
}