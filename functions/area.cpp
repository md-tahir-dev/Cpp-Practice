#include<iostream>
using namespace std;

float circleArea(float radius)
{
    // float radius;
    // cout<<"Enter a radius: ";
    // cin>>radius;
    float rad = 3.14*radius*radius;
  
    return rad;
}

int main()
{   
    float radius;
    cout<<"Enter a radius: ";
    cin>>radius;
  
    float radi= circleArea(radius);
    cout<<"Area is: "<<radi<<endl;
    return 0;
}