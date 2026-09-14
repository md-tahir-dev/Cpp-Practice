// Create a structure named Employee with fields: ID, Name, Salary. Write a program to input details of 5 employees and display the record of the employee with the highest salary.
#include <iostream>
#include <string>
using namespace std;
typedef struct employee
{
    int ID;
    string name;
    double Salary;
}ep;

int main()
{   
    int n = 5;
    ep employee[n];
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter the data of "<<i+1<<" employee."<<endl;
        cout<<"Enter Employee ID: ";
        cin>>employee[i].ID;
        cout<<endl;

        cin.ignore();
        
        cout<<"Enter Employee Name: ";
        getline(cin,employee[i].name);
        cout<<endl;
        
        cout<<"Enter Employee salary: ";
        cin>>employee[i].Salary;
        cout<<endl;
    }
    int IndexMAX = 0; 
    for (size_t i = 1; i < n; i++)
    {
        if(employee[i].Salary>employee[IndexMAX].Salary)
        {
            IndexMAX=i;
        }
    }
    cout<<"Id: "<<employee[IndexMAX].ID<<endl;
    cout<<"Id: "<<employee[IndexMAX].name<<endl;
    cout<<"Id: "<<employee[IndexMAX].Salary<<endl;
    return 0;
}