#include <iostream>
#include<string>
using namespace std;
class Teacher{
private:
    double salary;
public:
    string name;
    string subject;
    string dept;
    

    void ChangeDept(string newdept)
    {   
        // this is method
        dept=newdept;
    }
    void setSalary(double s)//setter
    {
        salary = s;
    }
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    Teacher t1;
    t1.name="Muhammad";
    t1.subject="C++";
    t1.dept="Computer Science";
    // t1.salary=25000;
    t1.setSalary(25000);

    cout<<t1.name<<endl;
    cout<<t1.getSalary()<<endl;
    return 0;
}