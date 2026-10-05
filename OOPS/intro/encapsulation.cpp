#include <iostream>
using namespace std;
class student
{
private:
    string name;
    int age;
    float heigth;//data member
public:
    int getAge(){
        return this->age;
    }
};

int main()
{
    student muhammad;
    cout<<"All ok"<<endl;   
    return 0;
}