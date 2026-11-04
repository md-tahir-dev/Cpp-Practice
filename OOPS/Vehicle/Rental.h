#pragma once
#include <string>
using namespace std;
class Rental
{
private:
    int customerID;
    int rentalID;
    int vehicleID;
    int DurationinDay;
    int rentperDay;
    int totalrent;
public:
    Rental(int customerID, int RentalID, int VehicleID, int Duration, int RentperDay);
    int GetCustomerID() const;
    int GetRentalID() const;
    int GetVehicleID() const;
    int GetDuration() const;
    int GetRentperDay() const;
    int GetTotalrent() const;
};


