#include <iostream>
using namespace std;
class animal
{
public:
    float weight;
    float height;
    int age;
    void eat(){
        cout<<"Eating"<<endl;
    }
};
class dog:public animal{
    public:
    void bark(){
        cout<<"Dog barks"<<endl;
    }
    void display(){
        cout<<"Dog weight is "<<this->weight<<endl;
        cout<<"Dog height is "<<this->height<<endl;
        cout<<"Dog age is "<<this->age<<endl;
        bark();
    }
};

int main()
{
    dog pet1;

    pet1.weight=15.3;
    pet1.height=2.7;
    pet1.age=3;

    // pet1.bark();
    pet1.display();
    return 0;
}