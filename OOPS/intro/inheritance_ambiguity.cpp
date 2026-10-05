#include <iostream>
using namespace std;

class Person {
public:
    void introduce() {
        cout << "I am a person." << endl;
    }
};

class Student :  public Person { 
public:    
    void work(){
        cout<<"I work in university"<<endl;
    }
};

class Employee : public Person { 
public:
    void work(){
    cout<<"I work in office"<<endl;
}
};
class Intern : public Student, public Employee { };

int main() {
    Intern i;
    // i.introduce();  
    i.Employee::work();
    i.Student::work();
    return 0;
}
