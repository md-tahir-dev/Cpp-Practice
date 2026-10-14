#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
class Employee:public Person { protected: double salary; public: Employee(string id="",string name="",double salary=0); double getSalary()const; };
#endif
