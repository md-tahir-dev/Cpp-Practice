#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

// Default constructor: origin (0, 0)
Point::Point() : x(0), y(0)
{
}

// Both coordinates given
Point::Point(int x, int y) : x(x), y(y)
{
}

// Only x given, y defaults to 0
Point::Point(int x) : x(x), y(0)
{
}

void Point::setX(int newX)
{
    x = newX;
}

void Point::setY(int newY)
{
    y = newY;
}

void Point::setCoordinates(int newX, int newY)
{
    x = newX;
    y = newY;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::displayPoint() const
{
    cout << "(" << x << ", " << y << ")";
}
void Point::writeToFile(ofstream& fileOut) const
{
    fileOut<<x<<" "<<y<<endl;
}
void Point::readFromfile(ifstream& fileIn)
{
    fileIn>>x>>y;
}