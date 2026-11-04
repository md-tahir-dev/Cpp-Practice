#include "Vehicle.h"

#include <iostream>
#include <stdexcept>

Vehicle::Vehicle(int vehicleID, std::string brand, int modelYear,
                 double rentalPricePerDay)
    : vehicleID(vehicleID),
      brand(brand),
      modelYear(modelYear),
      rentalPricePerDay(rentalPricePerDay),
      available(true) {
    if (vehicleID <= 0) {
        throw std::invalid_argument("Vehicle ID must be positive.");
    }
    if (brand.empty()) {
        throw std::invalid_argument("Vehicle brand cannot be empty.");
    }
    if (modelYear <= 0) {
        throw std::invalid_argument("Vehicle model year must be positive.");
    }
    if (rentalPricePerDay <= 0) {
        throw std::invalid_argument("Rental price per day must be positive.");
    }
}

Vehicle::~Vehicle() = default;

int Vehicle::getID() const {
    return vehicleID;
}

const std::string& Vehicle::getBrand() const {
    return brand;
}

int Vehicle::getModelYear() const {
    return modelYear;
}

double Vehicle::getRentalPricePerDay() const {
    return rentalPricePerDay;
}

bool Vehicle::getAvailable() const {
    return available;
}

bool Vehicle::rent() {
    if (!available) {
        return false;
    }
    available = false;
    return true;
}

bool Vehicle::returnVehicle() {
    if (available) {
        return false;
    }
    available = true;
    return true;
}

double Vehicle::calculateRentalCost(int days) const {
    if (days <= 0) {
        throw std::invalid_argument("Rental days must be positive.");
    }
    return rentalPricePerDay * days;
}

Car::Car(int vehicleID, std::string brand, int modelYear,
         double rentalPricePerDay, int seats)
    : Vehicle(vehicleID, brand, modelYear, rentalPricePerDay), seats(seats) {
    if (seats <= 0) {
        throw std::invalid_argument("Car seat count must be positive.");
    }
}

int Car::getSeats() const {
    return seats;
}

double Car::calculateRentalCost(int days) const {
    return Vehicle::calculateRentalCost(days);
}

void Car::displayInfo() const {
    std::cout << "Vehicle ID: " << getID()
              << "\nBrand: " << getBrand()
              << "\nModel year: " << getModelYear()
              << "\nRental price per day: " << getRentalPricePerDay()
              << "\nSeats: " << seats
              << "\nAvailability: " << (getAvailable() ? "Available" : "Not available")
              << std::endl;
}

Motorcycle::Motorcycle(int vehicleID, std::string brand, int modelYear,
                       double rentalPricePerDay, int engineCapacity)
    : Vehicle(vehicleID, brand, modelYear, rentalPricePerDay),
      engineCapacity(engineCapacity) {
    if (engineCapacity <= 0) {
        throw std::invalid_argument("Engine capacity must be positive.");
    }
}

int Motorcycle::getEngineCapacity() const {
    return engineCapacity;
}

double Motorcycle::calculateRentalCost(int days) const {
    const double baseCost = Vehicle::calculateRentalCost(days);
    return engineCapacity >= 500 ? baseCost * 1.15 : baseCost;
}

void Motorcycle::displayInfo() const {
    std::cout << "Vehicle ID: " << getID()
              << "\nBrand: " << getBrand()
              << "\nModel year: " << getModelYear()
              << "\nRental price per day: " << getRentalPricePerDay()
              << "\nEngine capacity: " << engineCapacity << " cc"
              << "\nAvailability: " << (getAvailable() ? "Available" : "Not available")
              << std::endl;
}

Van::Van(int vehicleID, std::string brand, int modelYear,
         double rentalPricePerDay, double cargoVolume)
    : Vehicle(vehicleID, brand, modelYear, rentalPricePerDay),
      cargoVolume(cargoVolume) {
    if (cargoVolume <= 0) {
        throw std::invalid_argument("Cargo volume must be positive.");
    }
}

double Van::getCargoVolume() const {
    return cargoVolume;
}

double Van::calculateRentalCost(int days) const {
    const double baseCost = Vehicle::calculateRentalCost(days);
    return baseCost * (1.0 + cargoVolume * 0.02);
}

void Van::displayInfo() const {
    std::cout << "Vehicle ID: " << getID()
              << "\nBrand: " << getBrand()
              << "\nModel year: " << getModelYear()
              << "\nRental price per day: " << getRentalPricePerDay()
              << "\nCargo volume: " << cargoVolume << " cubic meters"
              << "\nAvailability: " << (getAvailable() ? "Available" : "Not available")
              << std::endl;
}