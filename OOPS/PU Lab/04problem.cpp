#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;
class Circle
{
private:
    double radius;
    double originx;
    double originy;

public:
    Circle()
    {
        this->radius=0;
        this->originx=0;
        this->originy=0;
    }
    Circle(double radius, double originx, double originy)
        :   radius(radius), originx(originx), originy(originy) {}
    void setRadius(double radius)
    {
        if(radius<0)
        {
            throw invalid_argument("You entered negative value.");
        }
        this->radius=radius;
    }
    void setOriginX(double originX)
    {
        if(originX<0)
        {
            throw invalid_argument("You entered negative value.");
        }
        this->originx=originX;
    }
    void setOriginY(double originY)
    {
        if(originY<0)
        {
            throw invalid_argument("You entered negative value.");
        }
        this->originy=originY;
    }

    double GetRadius() const
    {
        return radius;
    }
    double GetOriginX() const
    {
        return originx;
    }
    double GetOriginY() const
    {
        return originy;
    }

    double getArea() const
    {
        return 3.14*(radius*radius);
    }

    double getCircumference() const
    {
        return 2*3.14*radius;
    }

    double getDiameter() const
    {
        return 2*radius;
    }
};
bool isConcentric(const Circle& c1, const Circle& c2)
{
    return (c1.GetOriginX()==c2.GetOriginX()&&c1.GetOriginY()==c2.GetOriginY());
}
int main()
{
    // (a) task
    Circle cir;
    cir.setRadius(2.32);
    cout<<"Area of circle: "<<cir.getArea()<<endl;
    cout<<"Area of Circumference: "<<cir.getCircumference()<<endl;
    cout<<"Area of Diameter: "<<cir.getDiameter()<<endl;
    
    // (b) task
    cout<<"Circle 2: "<<endl;
    Circle cir2(8.334,5 ,5);
    cout<<"Area of circle: "<<cir2.getArea()<<endl;
    cout<<"Area of Circumference: "<<cir2.getCircumference()<<endl;
    cout<<"Area of Diameter: "<<cir2.getDiameter()<<endl;
    cout<<"Circle 3: "<<endl;
    Circle cir3(3.56,5 ,7);
    cout<<"Area of circle: "<<cir3.getArea()<<endl;
    cout<<"Area of Circumference: "<<cir3.getCircumference()<<endl;
    cout<<"Area of Diameter: "<<cir3.getDiameter()<<endl;
    cout<<"Circle 3: "<<endl;
    Circle cir4(4.5663,5 ,7);
    cout<<"Area of circle: "<<cir4.getArea()<<endl;
    cout<<"Area of Circumference: "<<cir4.getCircumference()<<endl;
    cout<<"Area of Diameter: "<<cir4.getDiameter()<<endl;

    cout<<"Concentric Checks:-"<<endl;
    cout<<"\nAre circle2 and circle3 concentric? "<<(isConcentric(cir2,cir3)? "Yes": "No");
    cout<<"\nAre circle3 and circle4 concentric? "<<(isConcentric(cir3,cir4)? "Yes": "No")<<endl;

    // (c) task
    vector <pair<double,string>> circles;
    circles.push_back({cir.GetRadius(),"Circle 1"});
    circles.push_back({cir2.GetRadius(),"Circle 2"});
    circles.push_back({cir3.GetRadius(),"Circle 3"});
    circles.push_back({cir4.GetRadius(),"Circle 4"});

    sort(begin(circles),end(circles));

    for(int i =0; i<circles.size(); i++)
    {
        cout<<circles[i].second<<" has a Label: "<<(i+1)<<endl;
    }

    // (d) task
    cout<<"\nCircles with diameter greater than 12: "<<endl;
    if(cir.getDiameter()>12)
    {
        cout<<"Circle 1"<<endl;
    }
    if(cir2.getDiameter()>12)
    {
        cout<<"Circle 2"<<endl;
    }
    if(cir3.getDiameter()>12)
    {
        cout<<"Circle 3"<<endl;
    }
    if(cir4.getDiameter()>12)
    {
        cout<<"Circle 4"<<endl;
    }
    return 0;
}