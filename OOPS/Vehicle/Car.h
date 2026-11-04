#pragma once
#include<string>
#include "vehicle.h"
using namespace std;
class Car: public Vehicle
{
private:
    int noofSeats;
public:
    Car(int vehicleID, string brand, string model, double rentPerDay, int noofseats=5);
    int GetSeats() const;
};

