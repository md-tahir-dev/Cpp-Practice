#include "RentalSystem.h"

#include <stdexcept>
#include <utility>

RentalSystem::RentalSystem() = default;

void RentalSystem::addVehicle(unique_ptr<Vehicle> vehicle)
{
    if (!vehicle)
    {
        throw invalid_argument("Vehicle Invalid.");
    }

    vehicles.push_back(move(vehicle));
}

void RentalSystem::addCustomer(const customer& newCustomer)
{
    customers.push_back(newCustomer);
}

void RentalSystem::addRental(const Rental& rental)
{
    rentals.push_back(rental);
}

const vector<unique_ptr<Vehicle>>& RentalSystem::getVehicles() const
{
    return vehicles;
}

const vector<customer>& RentalSystem::getCustomers() const
{
    return customers;
}

const vector<Rental>& RentalSystem::getRentals() const
{
    return rentals;
}
