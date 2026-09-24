#include <iostream>
#include<string>
using namespace std;
class student
{
public:
    string name; 
    double cgpa;
    student(string name, double cgpa)
    {
        this->name=name;
        this->cgpa=cgpa;
    } 
    void getinfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};

int main()
{
    student s1("Muhammad", 3.43);
    s1.getinfo();
    student s2(s1);
    s2.getinfo();
    return 0;
}