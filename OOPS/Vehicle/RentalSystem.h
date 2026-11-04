#pragma once
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "vehicle.h"
#include "Customer.h"
#include "Rental.h"
using namespace std;

class RentalSystem
{
private:
    vector<unique_ptr<Vehicle>> vehicles;
    vector<customer> customers;
    vector<Rental> rentals;

public:
    RentalSystem();

    void addVehicle(unique_ptr<Vehicle> vehicle);
    void addCustomer(const customer& newCustomer);
    void addRental(const Rental& rental);

    const vector<unique_ptr<Vehicle>>& getVehicles() const;
    const vector<customer>& getCustomers() const;
    const vector<Rental>& getRentals() const;
};
