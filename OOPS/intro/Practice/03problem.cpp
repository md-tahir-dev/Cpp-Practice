/*
Create:

class Employee
Private members
name
employeeID
salary
Constructor

Initialize all three.

Rules:

name cannot be empty.
employeeID must be greater than 0.
salary cannot be negative.
If salary is negative, initialize it to 0.
Functions

Create:

setSalary(double salary)
getSalary()
giveRaise(double percentage)
getAnnualSalary()
displayEmployee()
Rules

setSalary():

salary >= 0

giveRaise():

percentage > 0

For example:

salary = 50,000
raise = 10%

new salary = 55,000

getAnnualSalary() should calculate:

monthly salary × 12
Test in main()

Create at least 3 employees.

Test:

Normal employee
Negative salary
Invalid salary through setSalary()
Give a raise
Display annual salary
Try a negative raise
Important

This time, don't add requirements that I didn't ask for.

For example, don't add:

age
department
designation
bonus
tax
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Employee
{
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string name, int id, double sal)
    {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            cout << "Name cannot be empty. Setting to 'Unknown'." << endl;
            this->name = "Unknown";
        }
        if (id > 0)
        {
            this->employeeID = id;
        }
        else
        {
            cout << "EmployeeID must be greater than 0. Setting to 0." << endl;
            this->employeeID = 0;
        }
        if (sal >= 0)
        {
            this->salary = sal;
        }
        else
        {
            cout << "Salary cannot be negative. Setting to 0." << endl;
            this->salary = 0;
        }
    }
    void setSalary(double salary)
    {
        if (salary >= 0)
        {
            this->salary = salary;
        }
        else
        {
            cout << "Invalid salary. Salary cannot be negative." << endl;
        }
    }
    double getSalary()
    {
        return salary;
    }
    void giveRaise(double percentage)
    {
        if (percentage > 0)
        {
            salary = salary + (salary * percentage / 100);
        }
        else
        {
            cout << "Invalid raise percentage." << endl;
        }
    }
    double getAnnualSalary()
    {
        return salary * 12;
    }
    void displayEmployee()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee id: " << employeeID << endl;
        cout<<fixed<<setprecision(2);
        cout << "Employee salary: " << salary << endl;
        cout << "Employee Annual salary: " << getAnnualSalary() << endl;
    }
};
int main()
{
    Employee ali("Ali", 1001, 90000.50);
    ali.displayEmployee();
    ali.giveRaise(15);
    ali.displayEmployee();

    Employee sara("Sara", 1002, -20000);
    sara.displayEmployee();

    // Invalid salary through setSalary
    Employee john("John", 1003, 30000);
    john.displayEmployee();
    john.setSalary(-5000); // invalid
    john.displayEmployee();

    john.giveRaise(-5); // invalid
    john.displayEmployee();

    return 0;
}