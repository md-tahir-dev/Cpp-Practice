#include "Rental.h"
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;
Rental::Rental(int customerID, int RentalID, int VehicleID, int Duration, int RentperDay)
{
    if(customerID<=0)
    {
        throw runtime_error("You entered invalid id."); 
    }
    else
    {
        this->customerID=customerID;
    }
    if(RentalID<=0)
    {
        throw runtime_error("You entered invalid id."); 
    }
    else
    {
        this->rentalID=RentalID;
    }
    if(VehicleID<=0)
    {
        throw runtime_error("You entered invalid id."); 
    }
    else
    {
        this->vehicleID=VehicleID;
    }
    this->DurationinDay=Duration;
    this->rentperDay=RentperDay;
}

int Rental::GetCustomerID() const
{
    return customerID;
}

int Rental::GetRentalID() const
{
    return rentalID;
}
int Rental::GetVehicleID() const
{
    return vehicleID;
}
int Rental::GetDuration() const
{
    return DurationinDay;
}
int Rental::GetRentperDay() const
{
    return rentperDay;
}
int Rental::GetTotalrent() const
{
    return rentperDay*DurationinDay;
}