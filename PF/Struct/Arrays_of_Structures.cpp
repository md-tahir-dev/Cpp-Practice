#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int Eid;
    string Ename;
    string Edep;
    float Esalary;
};

int main() {
    Employee staff[3]; // array of 3 employees

    staff[0] = {1, "Ali", "IT", 20.5};
    staff[1] = {2, "Sara", "HR", 18.0};
    staff[2] = {3, "Tahir", "CS", 25.0};

    for(int i=0; i<3; i++) {
        cout << staff[i].Eid << " - " << staff[i].Ename 
             << " - " << staff[i].Edep 
             << " - " << staff[i].Esalary << endl;
    }
    return 0;
}
