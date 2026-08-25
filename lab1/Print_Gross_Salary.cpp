/*
Print Gross Salary:
A company gives its employees a basic salary and provides the following allowances:
• House Rent Allowance (HRA) = 20% of basic salary
• Dearness Allowance (DA) = 50% of basic salary
• Gross Salary = Basic Salary + HRA + DA
Write a program that takes the basic salary as input and calculates an employee's Gross Salary.

*/

#include <iostream>
using namespace std;
void grosssalcal(double basicsalary, double grosssalary)
{
    double onepersal=basicsalary/100;
    double House_Rent= onepersal*20;
    double Dearness_Allowance= onepersal*50;
    grosssalary = basicsalary+House_Rent+Dearness_Allowance;
    cout<<"Gross Salary is: "<<grosssalary;
}
int main()
{
    double basicsalary, grosssalary;
    cout<<"Enter your basic salary: ";
    cin>>basicsalary;
    grosssalcal(basicsalary,grosssalary);
    return 0;
}