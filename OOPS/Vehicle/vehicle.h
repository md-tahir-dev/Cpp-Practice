#pragma once
#include<string>
using namespace std;
class Vehicle
{
protected:
    int vehicleID;
    string brand;
    string model;
    double rentPerDay;
    bool available;

public:
    Vehicle(int vehicleID, string brand, string model, double rentPerDay);
    virtual ~Vehicle() = default;
    virtual int getID() const;
    virtual string Getbrand() const;
    virtual string GetModel() const;
    virtual double GetRent() const;
    virtual bool isAvailable() const;

};
