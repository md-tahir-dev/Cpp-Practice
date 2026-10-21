/*
Employee Records

Topics: Member initializer lists, constructor overloading, constructor delegation.
Create an Employee class with private members:
- name (string)
- employeeID (int)
- salary (double)
Requirements:
1. Create a default constructor.
2. Create a parameterized constructor using a member initializer list.
3. Create another constructor that accepts only the employee's name and ID.
4. Use constructor delegation to avoid repeating initialization logic.
5. Create a display() function.
6. Test every constructor by creating objects.
Challenge: Ensure that all constructors initialize every data member correctly.
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee() : name("Unknown"), employeeID(0), salary(0.0) {
        cout << "Default constructor called." << endl;
    }

    Employee(string name, int id, double sal) 
        : name(name), employeeID(id), salary(sal) {
        cout << "Parameterized constructor called." << endl;
    }

    Employee(string name, int id) 
        : Employee(name, id, 0.0) {   // delegates to constructor above
        cout << "Delegating constructor called." << endl;
    }

    void display() const {
        cout << "Name: " << name << endl
             << "Employee ID: " << employeeID << endl
             << "Salary: " << salary << endl;
    }
};

int main() {
    Employee e1;
    e1.display();

    Employee e2("Ali", 1001, 50000.0);
    e2.display();

    Employee e3("Sara", 1002);
    e3.display();

    return 0;
}
