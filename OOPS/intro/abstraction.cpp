#include <iostream>
using namespace std;

class Animal
{
private:
    int age;

protected:
    string name;

public:
    // Constructor
    Animal(string n, int a)
    {
        name = n;
        age = a;
    }

    // Public function — interface
    void showAge()
    {
        cout << "Age: " << age << endl;
    }

    // Pure virtual function
    virtual void sound() = 0;
};

class Dog : public Animal
{
public:
    Dog(string n, int a) : Animal(n, a)
    {
    }

    void sound() override
    {
        cout << name << " barks" << endl;
    }
};

int main()
{
    Dog d("Tommy", 3);

    d.sound();
    d.showAge();

    return 0;
}