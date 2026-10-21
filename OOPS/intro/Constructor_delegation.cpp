#include <iostream>
#include <string>
using namespace std;

class Contact
{
private:
    string name;
    string email;
    string phone;

    void display(int n) const
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Phone: "<<phone<<endl;
    }
public:
    // Constructor #1 (default)
    Contact() : Contact("", "", "")
    { }

    // Constructor #2
    Contact(string n, string e, string p)
    {
        name = n;
        email = e;
        phone = p;
    }
    void display() const
    {
        display(3);
    }
};

int main()
{
    Contact c1;                                        // uses Constructor #1
    c1.display();
    Contact c2("Ali", "ali@example.com", "0300-1234567"); // uses Constructor #2
    c2.display();
    return 0;
}