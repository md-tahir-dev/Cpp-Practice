#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    double* cgpaPTR;
    Student (string name, double cgpa)
    {
        this->name=name;
        cgpaPTR = new double;
        *cgpaPTR = cgpa;
    }
    Student(Student &obj)
    {
        this->name=obj.name;
        cgpaPTR=new double;
        *cgpaPTR=*obj.cgpaPTR;
    }
    void getInfo()
    {
        cout<<"name: "<<name<<endl;
        cout<<"cgpa: "<<*cgpaPTR<<endl;
    }
};
int main()
{
    Student s1("Muhammad Tahir",3.76);
    Student s2(s1);
    s1.getInfo();
    *(s2.cgpaPTR)=3.87;
    // s1.getInfo();
    s2.name="Riya";
    s2.getInfo();
    return 0;
}