#include <iostream>
#include<string>
using namespace std;
class Teacher{
private:
    double salary;
public:
    Teacher()//non-parameterized
    {
        dept="Computer Science";    
    }
    Teacher(Teacher &ObjOrg)//copy constructor 
    {   
        cout<<"I am Default Copy Constructor...\n";
        this->name=ObjOrg.name;
        this->subject=ObjOrg.subject;
        this->dept=ObjOrg.dept;
        this->salary=ObjOrg.salary;
    }
    Teacher(string n, string sub, string d, double sal)//parameterized
    {
        name = n;
        subject = sub;
        dept = d;
        salary = sal;
    }
    string name;
    string subject;
    string dept;
    
    void getsalary(int sal)
    {
        salary = sal;
    }
    // void 
    void getinfo()
    {
        cout<<"Teacher Name: "<<name<<endl;
        cout<<"Teacher Subject: "<<subject<<endl;
        cout<<"Teacher Dept: "<<dept<<endl;
    }
};

int main()
{
    Teacher t1("Muhammad", "C++","Computer Science",25000 );
    t1.getinfo();
    cout<<endl;
    // Teacher t2(t1);//default copy constructor -> invoke
    Teacher t2(t1);//custom copy constructor
    t2.getinfo();
    cout<<endl;
    return 0;
}