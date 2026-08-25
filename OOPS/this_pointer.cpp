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
    Teacher(string name, string subject, string dept, double salary)//parameterized
    {
        this->name = name;
        this->subject = subject;
        this->dept = dept;
        this->salary = salary;
    }
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
    cout<<endl;
    return 0;
}