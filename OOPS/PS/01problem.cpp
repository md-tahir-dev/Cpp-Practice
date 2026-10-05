#include<iostream>
#include<string>
using namespace std;
class Student{
public:
    string name;
    int age;
    int marks;
    Student(string name,int age,int marks)
    {
        this->name=name;
        this->age=age;
        this->marks=marks;

    }
    Student()
    {
        name="";
        age=0;
        marks=-1;

    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        if(marks!=-1){cout<<"Marks: "<<marks<<endl;}
    }
};
int main()
{
    Student s1;
    s1.name="Ali";
    s1.age=20;
    s1.marks=85;
    Student s2("Ahmad",21,91);
    // s2.name="Ahmed";
    // s2.age=21;
    // s2.marks=91;
    cout<<"Student 1:"<<endl;
    s1.display();
    cout<<"Student 2:"<<endl;
    s2.display();
    return 0;
}