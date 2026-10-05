#include <iostream>
#include <string>

using namespace std;
struct student
{
private:
    string name;
    int age;
    double marks;
public:
    student(string studentName, int studentAge, double studentMarks)
        : name(studentName), age(studentAge), marks(studentMarks){}
    void data()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
};


int main()
{    string name;
    int age;
    double marks;
    cout<<"Enter name: "<<endl;
    cin>>name;
    cout<<"Enter age: "<<endl;
    cin>>age;
    cout<<"Enter marks: "<<endl;
    cin>>marks;
    student tahir(name, age, marks);
    tahir.data();
    return 0;
}