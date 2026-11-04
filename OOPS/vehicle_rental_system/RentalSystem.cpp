#include "RentalSystem.h"

#include "Vehicle.h"

#include <iostream>
#include <stdexcept>
#include <utility>
#include <fstream>


void RentalSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    if (!vehicle) {
        throw std::invalid_argument("Cannot add a null vehicle.");
    }
    if (findVehicleByID(vehicle->getID()) != nullptr) {
        throw std::invalid_argument("A vehicle with this ID already exists.");
    }
    vehicles.push_back(std::move(vehicle));
}

Vehicle* RentalSystem::findVehicleByID(int vehicleID) {
    for (const std::unique_ptr<Vehicle>& vehicle : vehicles) {
        if (vehicle->getID() == vehicleID) {
            return vehicle.get();
        }
    }
    return nullptr;
}

const Vehicle* RentalSystem::findVehicleByID(int vehicleID) const {
    for (const std::unique_ptr<Vehicle>& vehicle : vehicles) {
        if (vehicle->getID() == vehicleID) {
            return vehicle.get();
        }
    }
    return nullptr;
}

void RentalSystem::displayAllVehicles() const {
    if (vehicles.empty()) {
        std::cout << "No vehicles in the system." << std::endl;
        return;
    }

    for (const std::unique_ptr<Vehicle>& vehicle : vehicles) {
        vehicle->displayInfo();
    }
}

void RentalSystem::displayAvailableVehicles() const {
    bool foundAvailableVehicle = false;
    for (const std::unique_ptr<Vehicle>& vehicle : vehicles) {
        if (vehicle->getAvailable()) {
            vehicle->displayInfo();
            foundAvailableVehicle = true;
        }
    }

    if (!foundAvailableVehicle) {
        std::cout << "No available vehicles." << std::endl;
    }
}
void addCustomer(int cusID, string name, string CNIC, string password, string phone )
{
    
}
