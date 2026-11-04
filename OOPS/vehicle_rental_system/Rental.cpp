#include "Rental.h"

#include "Customer.h"
#include "Vehicle.h"

#include <iostream>
#include <stdexcept>

Rental::Rental(int rentalID, Customer& customer, Vehicle& vehicle, int days)
    : rentalID(rentalID),
      customer(&customer),
      vehicle(&vehicle),
      days(days),
      totalCost(0.0),
      returned(false) {
    if (rentalID <= 0) {
        throw std::invalid_argument("Rental ID must be positive.");
    }
    if (days <= 0) {
        throw std::invalid_argument("Rental days must be positive.");
    }

    const double calculatedCost = vehicle.calculateRentalCost(days);
    if (!vehicle.rent()) {
        throw std::logic_error("Vehicle is not available for rental.");
    }
    totalCost = calculatedCost;
}

int Rental::getRentalID() const {
    return rentalID;
}

int Rental::getDays() const {
    return days;
}

double Rental::getTotalCost() const {
    return totalCost;
}

bool Rental::isReturned() const {
    return returned;
}

void Rental::displayInfo() const {
    std::cout << "Rental ID: " << rentalID
              << "\nCustomer: " << customer->getName()
              << " (ID: " << customer->getID() << ")"
              << "\nVehicle ID: " << vehicle->getID()
              << "\nRental days: " << days
              << "\nTotal cost: " << totalCost
              << "\nStatus: " << (returned ? "Returned" : "Active")
              << std::endl;
}

void Rental::markReturned() {
    if (returned) {
        throw std::logic_error("Rental has already been returned.");
    }
    if (!vehicle->returnVehicle()) {
        throw std::logic_error("Vehicle availability is inconsistent with rental status.");
    }
    returned = true;
}