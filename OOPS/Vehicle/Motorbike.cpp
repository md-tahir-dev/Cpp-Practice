#include"Motorbike.h"
#include"vehicle.h"
#include<stdexcept>
using namespace std;
Motorbike::Motorbike(int vehicleID, string brand, string model, double rentPerDay)
                    : Vehicle(vehicleID, brand, model, rentPerDay) {}