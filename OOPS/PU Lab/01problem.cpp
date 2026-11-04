// Write a c++ program that uses classes and objects to calculate the area of a rectangle, circle, or square based on the user's choice and the dimensions they provide.
#include <iostream>
#include <string>
using namespace std;
class cal
{
private:
    double len;
    double width;
    double redius;
public:
    
    cal(double length=0, double width=0)
        : len(length), width(width), redius(0) {}

    double square()
    {
        return len*len;
    }
    double circle(double redius)
    {
        return 3.14*(redius*redius);
    }
    double redtenganle()
    {
        return len* width;
    }
};

int main()
{   
    int n;
    cout<<"Please enter the number corresponding to the shape you would like to calculate the area for: " 
    <<"\n1. Rectangle"  
    <<"\n2. Circle"  
    <<"\n3. Square  "<<endl;
    cin>>n;
    if(n==1)
    {
        double len, width;
        cout<<"Enter len and width: "<<endl;
        cin>>len>>width;
        cal rectangle(len, width);
        cout<<"Area: "<<rectangle.redtenganle();
    }
    if(n==3)
    {
        double len;
        cout<<"Enter len : "<<endl;
        cin>>len;
        cal length(len);
        cout<<"Area: "<<length.square();
    }
    else if(n==2)
    {
        double red;
        cout<<"Enter redius: "<<endl;
        cin>>red;
        cal calredius(red);
        cout<<"Area: "<<calredius.circle(red);
    }
    else
    {
        cout << "You Entered invalid number. " << endl;
    }
    return 0;
}