#include "Customer.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

namespace {
bool isBlank(const std::string& value) {
    return value.find_first_not_of(" \t\n\r") == std::string::npos;
}
}

Customer::Customer(int customerID, const std::string& name,
                   const std::string& contactInfo)
    : customerID(customerID), name(name), contactInfo(contactInfo) {
    if (customerID <= 0) {
        throw invalid_argument("Customer ID must be positive.");
    }
    if (isBlank(name)) {
        throw invalid_argument("Customer name cannot be empty.");
    }
    if (isBlank(contactInfo)) {
        throw invalid_argument("Customer contact information cannot be empty.");
    }
}

int Customer::getID() const {
    return customerID;
}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getContactInfo() const {
    return contactInfo;
}

void Customer::displayInfo() const {
    std::cout << "Customer ID: " << customerID
              << "\nName: " << name
              << "\nContact info: " << contactInfo
              << std::endl;
}
