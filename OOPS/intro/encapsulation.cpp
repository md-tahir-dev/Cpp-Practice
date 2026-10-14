#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    string name;
    int age;
    float heigth; // data member
public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setheight(float heigth)
    {
        this->heigth = heigth;
    }
    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Height: " << heigth << endl;
    }
    int getAge() const
    {
        return this->age;
    }
};

int main()
{
    /*
    width   ---> 2
    lenght  ---> 4
    
    area    --->8
    */
    student muhammad;
    cout << "All ok" << endl;
    muhammad.setName("Muhammad");
    muhammad.setAge(18);
    muhammad.setheight(5.11);
    muhammad.display();
    return 0;
}