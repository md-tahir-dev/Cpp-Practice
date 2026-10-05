#include <iostream>
using namespace std;
class Human{//parent class
protected:
    float height;
    int age;
    float weight;
    int getAge(){
        return this->age;
    }
    void setWeight(float w){
        this->weight=w;
    }
};
class Male: public Human{//child class
public:
    string color;
    void sleep(){
        cout<<"Male is sleeping."<<endl;
    }
    int getage()
    {
        return age;
    }
};
int main()
{
    Male object1;
    // cout<<object1.getage()<<endl; 
    // cout<<object1.weight<<endl; 
    // cout<<object1.height <<endl; 
    // cout<<object1.color <<endl; 
    // object1.setWeight(55);
    // cout<<object1.weight<<endl; 
    // object1.sleep();
    return 0;
}