#include <iostream>
using namespace std;

int main()
{
    int day;

    cout<<"Enter a number (1-7): ";
    cin >> day;

    switch(day)
    {
        case 1:
            cout << "Day 1 is Monday\n";
            break;

        case 2:
            cout << "Day 2 is Tuesday\n";
            break;

        case 3:
            cout << "Day 3 is Wednesday\n";
            break;

        case 4:
            cout << "Day 4 is Thursday\n";
            break;

        case 5:
            cout << "Day 5 is Friday\n";
            break;

        case 6:
            cout << "Day 6 is Saturday\n";
            break;

        case 7:
            cout << "Day 7 is Sunday\n";
            break;

        default:
            cout << "Invalid input! Please enter a number between 1 and 7.\n";
    }

    return 0;
}