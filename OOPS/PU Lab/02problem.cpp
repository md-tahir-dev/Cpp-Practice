#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class MotorVehicle
{
private:
    string make;
    string fuelType;
    int yearOfManufacture;
    string color;
    int engineCapacity;
public:
    MotorVehicle(string make, string fuelType, int yearOfManufacture, string color, int engineCapacity)
                : make(make), 
                fuelType(fuelType), 
                yearOfManufacture(yearOfManufacture), 
                color(color), 
                engineCapacity(engineCapacity) {}
    void setMake(string make)
    {
        this->make=make;
    }
    void setFuel(string Fueltype)
    {
        this->fuelType=fuelType;
    }
    void setYear(int yearOfManufacture)
    {   
        if(yearOfManufacture<=0)
        {
            throw invalid_argument("You entered invalid Year.");
        }
        this->yearOfManufacture=yearOfManufacture;
    }
    void setColor(string color)
    {
        this->color=color;
    }
    void SetengineCapacity(int engineCapacity)
    {
        this->engineCapacity=engineCapacity;
    }

    string GetMake() const
    {
        return make;
    }
    string GetFuel() const
    {
        return fuelType;
    }
    int Getyear() const
    {
        return yearOfManufacture;
    }
    string GetColor() const
    {
        return color;
    }
    int GetEngineCapacity() const
    {
        return engineCapacity;
    }

    void displayCarDetails() const
    {
        cout<<"\nMake: "<<make
            <<"\nFuel Type: "<<fuelType
            <<"\nYear of Manufacture: "<<yearOfManufacture
            <<"\nColor: "<<color
            <<"\nEngine Capacity: "<<engineCapacity
            <<endl;
    }
    void display() const
    {
        cout << this->color << endl;
    }
};
int main()
{
    MotorVehicle Car("Honda", "Petrol", 2023, "White", 2500);
    Car.display();
    return 0;
}