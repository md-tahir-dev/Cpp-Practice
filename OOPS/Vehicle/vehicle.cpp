#include "vehicle.h"
#include <stdexcept>
#include <fstream>

Vehicle::Vehicle(int vehicleID, string brand, string model, double rentPerDay)
    {
        if (vehicleID <= 0)
        {
            throw runtime_error("You entered invalid id."); 
        }
        else
        {
            this->vehicleID = vehicleID;
        }
        this->brand=brand;
        this->model=model;
        this->rentPerDay=rentPerDay;
        this->available=true;
    }

int Vehicle::getID() const
    {
        return vehicleID;
    }
string Vehicle::Getbrand() const
    {

        return brand;
    }
string Vehicle::GetModel() const
    {
        return model;
    }
double Vehicle::GetRent() const
    {
        return rentPerDay;
    }
bool Vehicle::isAvailable() const
    {
        return available;
    }
