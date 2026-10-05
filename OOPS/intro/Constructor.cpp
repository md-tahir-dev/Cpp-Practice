#include <iostream>
using namespace std;
class Hero
{
private:
        int health;
public:
    string name;
    char level;
    // non-parameterised constructor
    Hero(){
        cout<<"hello from constructor."<<endl;
    }
    // parameterised constructor
    Hero (int health){
        cout<<"second address is "<<this<<endl;
        this->health=health;
    }
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
    Hero ali(10);//statically
    cout<<"Address of ali is "<<&ali<<endl;
    Hero* ahmad=new Hero();//dynamically
    return 0;
}