#include <iostream>

using namespace std;
class human
{
    public:
        virtual void speak()
        {
            cout<<"Speak"<<endl;
        }
    };
    class dog:public human
    {
        public:
        void speak() override
        {
            cout<<"barks"<<endl;
        }

};

int main()
{
    human a;
    a.speak();
    dog b;
    b.speak();
    return 0;
}