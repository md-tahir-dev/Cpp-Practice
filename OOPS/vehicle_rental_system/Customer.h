#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customerID;
    std::string name;
    std::string contactInfo;

public:
    Customer(int customerID, const std::string& name, const std::string& contactInfo);

    int getID() const;
    const std::string& getName() const;
    const std::string& getContactInfo() const;

    void displayInfo() const;
};

#endif
