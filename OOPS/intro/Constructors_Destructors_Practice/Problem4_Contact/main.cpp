/*
Contact Information

Topics: C-strings, pointers, encapsulation, const getters, destructors.
Create a Contact class with private members:
- char* name
- char* phone
Requirements:
1. Create a default constructor.
2. Create a parameterized constructor that accepts a name and phone number.
3. Allocate memory dynamically for both C-strings and store their values.
4. Implement getters that provide read-only access to the stored strings.
5. Implement setters that update the strings safely.
6. Create a destructor that releases all dynamically allocated memory.
7. Test the class with multiple objects.
Challenge: Ensure that updating a string does not cause a memory leak or access to invalid memory.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Contact
{
private:
    char *name;
    char *phone;

public:
    Contact() : name(nullptr), phone(nullptr)
    {
        cout << "Default constructor called." << endl;
    };

    Contact(const char *n, const char *p)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        phone = new char[strlen(p) + 1];
        strcpy(phone, p);

        cout << "Paramrterized costructor called." << endl;
    };

    const char *getName() const
    {
        return name;
    }

    const char *getPhone() const
    {
        return phone;
    }

    void setName(const char *n)
    {
        if(!n){
            return;
        }
        char* newname = new char[strlen(n) + 1];
        strcpy(newname, n);
        delete[] name;
        name=newname;
    }

    void setPhone(const char *p)
    {
        if(!p)
        {
            return;
        }
        char* newphone = new char[strlen(p) + 1];
        strcpy(newphone, p);
        delete[] phone;
        phone=newphone;
    }

    void display() const
    {
        cout << "Name: " << (name ? name : "N/A") << endl;
        cout << "Phone: " << (phone ? phone : "N/A") << endl;
    }

    ~Contact()
    {
        delete[] name;
        delete[] phone;
        name = nullptr;
        phone = nullptr;
        cout << "Destructor called, memory released." << endl;
    }
};

int main()
{
    Contact c1;
    c1.display();

    Contact c2("Ali", "123456789");
    c2.display();

    c2.setName("Ahamd");
    c2.setPhone("987654321");
    c2.display();

    Contact c3("Sara", "555111222");
    c3.display();
    return 0;
}