#include <iostream>
using namespace std;

class Person
{
public:
    void introduce()
    {
        cout << "I am a person." << endl;
    }
};

class Student : public Person
{
public:
    void study()
    {
        cout << "I am studying." << endl;
    }
};

class Employee : public Person
{
public:
    void work()
    {
        cout << "I am working." << endl;
    }
};

class Intern : public Student, public Employee
{
public:
    void internship()
    {
        cout << "I am doing an internship." << endl;
    }
};

int main()
{
    Intern i;

    i.study();
    i.work();
    i.internship();

    return 0;
}