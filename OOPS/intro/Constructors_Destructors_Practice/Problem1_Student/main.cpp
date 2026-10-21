/*
Student Class

Topics: Default constructor, parameterized constructor, constructor overloading, getters and setters.
Create a Student class with private members:
- name (string)
- age (int)
- marks (double)
Requirements:
1. Create a default constructor that initializes the members with appropriate default values.
2. Create a parameterized constructor that accepts all three values.
3. Implement getters and setters for all members.
4. Create a display() function.
5. Create three objects: one using the default constructor and two using the parameterized constructor.
6. Modify one object's data using setters and display all three objects.
Challenge: Make sure your class works with both types of constructors.
*/

#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    string name="";
    int age=0;
    double marks=0.00;
public:
    Student() = default;    

    Student(string name, int age, double marks){
        this->name=name;
        this->age=age;
        this->marks=marks;
    }
    // setter
    void setName(string name){
        this->name=name;
    }
    void setAge(int Age){
        this->age=Age;
    }
    void setMarks(double Marks){
        this->marks=Marks;
    }
    // getter
    string getName()  const{
        return name;
    }
    int getAge()  const{
        return age;
    }
    double getMarks()  const{
        return marks;
    }

    void display() const{
        cout<<"Name: "<<getName()<<endl
            <<"Age: "<<getAge()<<endl
            <<"Marks: "<<getMarks()<<endl;
    }
};
int main()
{
    Student s1;
    s1.setName("Ali");
    s1.setAge(19);
    s1.setMarks(92);
    s1.display();
    s1.setMarks(93);
    s1.display();

    Student s2("Muhammad",18,89);
    Student s3("Ahmad",20,98);
    s2.display();
    s3.display();

    return 0;
}