#include<iostream>
#include<string>
using namespace std;

struct Employee {
    int Eid;
    string Ename;
    string Edep;
    float Esalary;
};

void printEmployee(Employee e) {
    cout << e.Eid << " - " << e.Ename 
         << " - " << e.Edep 
         << " - " << e.Esalary << endl;
}

int main() {
    Employee tahir = {1, "Muhammad Tahir", "CS", 15.5};
    printEmployee(tahir);
    return 0;
}
