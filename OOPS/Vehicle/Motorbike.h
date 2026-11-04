#pragma once 
#include <string> 
#include "vehicle.h"
using namespace std;
class Motorbike:public Vehicle
{
private:
    /* data */
public:
    Motorbike(int vehicleID, string brand, string model, double rentPerDay);
};

