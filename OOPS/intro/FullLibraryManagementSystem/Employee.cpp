#include "Employee.h"
Employee::Employee(string i,string n,double s):Person(i,n),salary(s<0?0:s){} double Employee::getSalary()const{return salary;}
