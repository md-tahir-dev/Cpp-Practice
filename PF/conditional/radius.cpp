#include<iostream>
using namespace std;
int main()
{
    float radius, diameter, circumference, area;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    circumference = 2 * 3.1415926535 * radius;
    cout << "\nThe circumference of the circle is: " << circumference;
    //pi r^2
    area = 3.1415926535 * radius * radius;
    cout << "\nThe area of the circle is: " << area;

        diameter = 2 * radius;
    cout<<endl;
    cout << "The diameter of the circle is: " << 1 <<endl;

    return 0;
}