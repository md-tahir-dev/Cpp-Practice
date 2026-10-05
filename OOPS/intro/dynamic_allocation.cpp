#include <iostream>
#include <string>

using namespace std;
class Hero
{
private:
        int health;
public:
    string name;
    char level;
    void sethealth(int h)
    {
        health=h;
    }
    int getHealth(){
        return health;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"Level: "<<level<<endl;
    }
};
int main()
{
    Hero *h1=new Hero;//dynamic allocation
    (*h1).print();
    Hero h2;//static allocation
    h2.print();
    return 0;
}