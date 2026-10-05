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
        cout << "Student is studying." << endl;
    }
};

class Employee : public Person
{
public:
    void work()
    {
        cout << "Employee is working." << endl;
    }
};

class CSStudent : public Student
{
public:
    void code()
    {
        cout << "CS student is coding." << endl;
    }
};

class ITStudent : public Student
{
public:
    void network()
    {
        cout << "IT student is working on networks." << endl;
    }
};

class Manager : public Employee
{
public:
    void manage()
    {
        cout << "Manager is managing." << endl;
    }
};

class Developer : public Employee
{
public:
    void develop()
    {
        cout << "Developer is developing software." << endl;
    }
};

int main()
{
    CSStudent s;

    s.introduce(); // Person
    s.study();     // Student
    s.code();      // CSStudent

    return 0;
}