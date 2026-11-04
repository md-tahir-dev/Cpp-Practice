#include "Car.h"
#include <stdexcept>

Car::Car(int CarID, string brand, string model, double rentPerDay, int numberOfSeats)
    : Vehicle(CarID, brand, model, rentPerDay), noofSeats(numberOfSeats)
{
    if(numberOfSeats<=0)
    {
        throw invalid_argument("Number of seats must be positive.");
    }
}

int Car::GetSeats() const
{
    return noofSeats;
}