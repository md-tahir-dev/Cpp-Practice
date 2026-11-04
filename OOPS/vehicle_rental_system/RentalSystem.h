#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <memory>
#include <vector>
#include <string>
using namespace std;
class Vehicle;

class RentalSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void addCustomer(int cusID, string name, string CNIC, string password, string phone );
    void findCustomerByID(int cusID);
    void displayCustomers();
    Vehicle* findVehicleByID(int vehicleID);
    const Vehicle* findVehicleByID(int vehicleID) const;

    void displayAllVehicles() const;
    void displayAvailableVehicles() const;
};

#endif