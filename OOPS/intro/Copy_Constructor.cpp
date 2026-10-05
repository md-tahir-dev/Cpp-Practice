#include <iostream>
#include <string>
using namespace std;
class Student{
public:
    string name;
    int marks;
    int age;
    Student(string name, int age, int marks){
        this->name=name;
        this->age=age;
        this->marks=marks;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"Age: "<<age<<endl;
    }
    Student(Student& ahmad){
        this->name=ahmad.name;
        this->marks=ahmad.marks;
        this->age=ahmad.age;
    }
};
int main()
{
    Student ali("Ali",20,78);
    // ali.name="Ali";
    // ali.age=20;
    // ali.marks=78;
    ali.print();
    Student ahamd(ali);
    return 0;
}