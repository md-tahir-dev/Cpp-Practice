#pragma once
#include <string>
#include <stdexcept>
using namespace std;
class customer
{
private:
    int customerID;
    string name;
    string CNIC;
    string Phone;
    string Address;
public:
    customer(int customerID, string name, string cnic, string phone, string address);
    int GetID() const;
    string Getname() const;
    string Getcnic() const;
    string Getphone() const;
    string Getaddress() const;    
};


