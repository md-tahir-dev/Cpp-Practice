#include<iostream>
#include<string>
using namespace std;

struct Address {
    string city;
    string country;
};

struct Employee {
    int Eid;
    string Ename;
    Address addr; // nested structure
    float Esalary;
};

int main() {
    Employee tahir;
    tahir.Eid = 1;
    tahir.Ename = "Muhammad Tahir";
    tahir.addr.city = "Lahore";
    tahir.addr.country = "Pakistan";
    tahir.Esalary = 15.5;

    cout << tahir.Ename << " lives in " 
         << tahir.addr.city << ", " 
         << tahir.addr.country << endl;
    return 0;
}
