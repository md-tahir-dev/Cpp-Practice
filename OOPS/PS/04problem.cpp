#include <iostream>

using namespace std;
class Baseclass{
    public:
        int var_base=11;
        virtual void display(){
            cout<<"1 Displaying Base class variable var_base: "<<var_base<<endl;
        }
};
class DerivedClass : public Baseclass
{
    public:
        int var_derived=22; 
        void display(){
            cout<<"2 Displaying Base class variable var_base: "<<var_base<<endl;
            cout<<"Displaying Derived class variable var_derived: "<<var_derived<<endl;
        }
};

int main()
{
    Baseclass* bptr;
    Baseclass obj_base;
    DerivedClass obj_derived;
    bptr = &obj_derived;
    bptr->display();  
    return 0;
}