#include <string>
#include <stdexcept>
#include <fstream>

#include "Customer.h"
using namespace std;
customer::customer(int customerID, string name, string cnic, string phone, string address)
{
    if(customerID<=0)
    {
        throw runtime_error("You entered invalid id."); 
    }
    else
    {
        this->customerID=customerID;
    }
    this->name=name;
    this->CNIC=cnic;
    this->Phone=phone;
    this->Address=address;
}
int customer::GetID() const
{
    return customerID;
}

string customer::Getname() const
{
    return name;
}
string customer::Getcnic() const
{
    return CNIC;
}
string customer::Getphone() const
{
    return Phone;
}
string customer::Getaddress() const
{
    return Address;
}    
