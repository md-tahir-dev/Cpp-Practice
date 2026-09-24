#include <iostream>
#include<string>
using namespace std;
typedef struct employee
{
    int Eid;
    string Ename;
    string Edep;
    float Esalaray;
}ep;

int main()
{
    ep tahir;
    tahir.Eid=1;
    tahir.Ename="Muhmmad Tahir";
    tahir.Edep="CS";
    tahir.Esalaray=15.5;
    cout<<"The value is: "<<tahir.Eid<<endl;
    cout<<"The value is: "<<tahir.Ename<<endl;
    cout<<"The value is: "<<tahir.Edep<<endl;
    cout<<"The value is: "<<tahir.Esalaray<<endl;
    return 0;
}