#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int age;
public:
    // Parameterized constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
        cout << "Constructor called for " << name << endl;
    }

    // Display function
    void display()
    {
        cout << "Student name: " << name << endl;
        cout << "Student age: " << age << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};

int main()
{
    Student s1("Ali", 20);
    Student s2("Ahmed", 21);

    cout << "\nDisplaying students:" << endl;
    s1.display();
    s2.display();

    // When main ends, destructors will run automatically
    return 0;
}
