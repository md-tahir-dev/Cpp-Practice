#include <iostream>
#include <string>
using namespace std;
class Hero
{
private:
        int health;
public:
    string name;//properties
    char level;
    void sethealth(int h)
    {
        health=h;
    }
    int getHealth(){
        return health;
    }
    void print(){
        cout<<"Name: "<<name<<" size of name: "<<sizeof(name)<<endl;
        cout<<"Health: "<<health<<" size of health: "<<sizeof(health)<<endl;
        cout<<"Level: "<<level<<" size of level: "<<sizeof(level)<<endl;
    }
};
int main()
{
    Hero h1;//h1 is object
    cout<<"size of class "<<sizeof(Hero)<<endl;
    h1.name="Paul";
    h1.sethealth(90);
    h1.level='B';
    cout << "size: " <<sizeof(h1)<<endl;
    cout<<"health is "<<h1.getHealth()<<endl;
    h1.print();
    return 0;
}