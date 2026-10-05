#include <iostream>

using namespace std;
class A{
    public:
    int sayHello(){
        cout<<"Hello, Love Harry"<<endl;
        return 1;
    }
    int sayHello(string name, int n){
        cout<<"Hello "<<name<<endl;
    }
};
int main()
{
    A obj;
    obj.sayHello();  
    obj.sayHello("Muhammad",8);  
    return 0;
}