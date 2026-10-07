/*
Create a class:

Student
Private members
name → string
rollNumber → int
marks → double
Requirements
Constructor

Initialize all three values.

A student's marks must be between:

0 and 100

If invalid marks are supplied, set them to 0.

Functions

Create:

setMarks(double marks)
getMarks()
getGrade()
displayStudent()

setMarks() must reject marks below 0 or above 100.

getGrade() should return:

90 - 100  → A
80 - 89   → B
70 - 79   → C
60 - 69   → D
Below 60  → F
Main

Create at least 3 students.

Test:

valid marks
invalid marks such as -10
invalid marks such as 150
changing marks using setMarks()
displaying each student's grade
*/

#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int rollNumber;
    double marks;
public:
    Student(string name, int rollno, double marks)
    {
        this->name = name;
        this->rollNumber = rollno;
        if (marks <= 100 && marks >= 0)
        {
            this->marks = marks;
        }
        else
        {
            cout << "Invalid initial marks. Setting marks to 0." << endl;
            this->marks = 0;
        }
    }
    void setMarks(double marks)
    {
        if (marks <= 100 && marks >= 0)
        {
            this->marks = marks;
            cout << "Marks changed successfully. New Marks: " << marks << endl;
        }
        else
        {
            cout << "You entered invalid marks " << marks << ". Your previous marks is stil." << endl;
        }
    }
    double getMarks()
    {
        return marks;
    }
    char getGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 70) return 'C';
        else if (marks >= 60) return 'D';
        else return 'F';
    }
    void displayStudent()
    {
        cout << "Your name is " << name << endl;
        cout << "Your roll no is " << rollNumber << endl;
        cout << "Your marks is " << marks << endl;
        cout << "Your grade is " << getGrade() << endl;
    }
};

int main()
{
    Student ali("Ali", 101, 87);
    // ali.setMarks(76.5);
    ali.getMarks();
    ali.getGrade();
    ali.displayStudent();

    Student sara("Sara", 102, -10); // invalid marks
    sara.displayStudent();

    Student john("John", 103, 150); // invalid marks
    john.displayStudent();

    ali.setMarks(95); // valid change
    ali.displayStudent();

    sara.setMarks(105); // invalid change
    sara.displayStudent();
    return 0;
}