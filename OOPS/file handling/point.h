#ifndef POINT_H
#define POINT_H

#include <fstream> 
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point();
    Point(int,int);
    Point(int);


    void setX(int);
    void setY(int);
    void setCoordinates(int,int);
    int getX() const;
    int getY() const;
    void displayPoint() const;
    void writeToFile(ofstream&) const;
    void readFromfile(ifstream&);
};
#endif