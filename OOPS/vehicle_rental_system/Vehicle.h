#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    int vehicleID;
    std::string brand;
    int modelYear;
    double rentalPricePerDay;
    bool available;

public:
    Vehicle(int vehicleID, std::string brand, int modelYear, double rentalPricePerDay);
    virtual ~Vehicle();

    int getID() const;
    const std::string& getBrand() const;
    int getModelYear() const;
    double getRentalPricePerDay() const;
    bool getAvailable() const;

    bool rent();
    bool returnVehicle();

    virtual double calculateRentalCost(int days) const;
    virtual void displayInfo() const = 0;
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(int vehicleID, std::string brand, int modelYear, double rentalPricePerDay, int seats);

    int getSeats() const;
    double calculateRentalCost(int days) const override;
    void displayInfo() const override;
};

class Motorcycle : public Vehicle {
private:
    int engineCapacity;

public:
    Motorcycle(int vehicleID, std::string brand, int modelYear, double rentalPricePerDay,
               int engineCapacity);

    int getEngineCapacity() const;
    double calculateRentalCost(int days) const override;
    void displayInfo() const override;
};

class Van : public Vehicle {
private:
    double cargoVolume;

public:
    Van(int vehicleID, std::string brand, int modelYear, double rentalPricePerDay,
        double cargoVolume);

    double getCargoVolume() const;
    double calculateRentalCost(int days) const override;
    void displayInfo() const override;
};

#endif
