#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override//override
    {
        cout << "Dog barks  " << endl;
    }
};
class Cat:public Animal
{
    public:
};
int main()
{
    Animal a1;
    a1.sound();
    Dog a2;
    a2.sound();
    Cat a3;
    a3.sound();
    return 0;
}