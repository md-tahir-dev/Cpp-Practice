#include <iostream>
using namespace std;
class animal
{
public:
    float weight;
    float height;
    int age;
    void bark(){
        cout<<"Baarking"<<endl;
    }
};

class human{
    public:
        string color;
        void speak(){
            cout<<"Speaking"<<endl;
        }
};
// Multiple inharitance
class hybrid: public animal, public human{

};
int main()
{
    hybrid obj1;
    obj1.speak();
    obj1.bark();
    return 0;
}