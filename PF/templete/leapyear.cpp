#include <iostream>
using namespace std;
void isleapyear(size_t year)
{
    if( year%4 == 0 && year%100 != 0 || year%400 == 0 )
    {
        cout<<"Leap Year";
    }
    else
    {
        cout<<"Not Leap Year";
    }
}
int main()
{
    size_t year;
    cout<<"Enter year: ";
    cin>>year;
    isleapyear(year);
    return 0;
}