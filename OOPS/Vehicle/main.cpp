#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <memory>

#include "Car.h"
#include "Customer.h"
#include "Rental.h"
#include "Motorbike.h"
#include "RentalSystem.h"

using namespace std;
int main()
{
    RentalSystem rentalSystem;

    Car civic(1,"Honda","2024", 10000.0, 4);
    rentalSystem.addVehicle(unique_ptr<Vehicle>(new Car(1, "Honda", "Civic 2024", 10000.0, 4)));
    cout<<"\nVehicle id: "<<civic.getID()
        <<"\nVehicle Brand: "<<civic.Getbrand()
        <<"\nVehicle model: "<<civic.GetModel()
        <<"\nVehicle Rent: "<<civic.GetRent()
        <<"\nIs vehicle available: "<<civic.isAvailable()
        <<"\nNumber of seats: "<<civic.GetSeats()<<endl;
        
    customer muhammad(1, "Muhammad","3520201588945", "03001234567","194-A Sabzazar");
        cout<<"\nCustomer id: "<<muhammad.GetID()
        <<"\nCustomer name: "<<muhammad.Getname()
        <<"\nCustomer cnic: "<<muhammad.Getcnic()
        <<"\nCustomer phone: "<<muhammad.Getphone()
        <<"\nCustomer Address: "<<muhammad.Getaddress()<<endl;
        
    Rental currentRental(muhammad.GetID(),1, civic.getID(), 5, civic.GetRent());
    rentalSystem.addCustomer(muhammad);
    rentalSystem.addRental(currentRental);
        cout<<"\nRental ID: "<<currentRental.GetRentalID()
        <<"\nLinked Customer ID: "<<currentRental.GetCustomerID()
        <<"\nVehicle ID: "<<currentRental.GetVehicleID()
        <<"\nDuration in day: "<<currentRental.GetDuration()
        <<"\nPer day rent: "<<currentRental.GetRentperDay()
        <<"\nTotal Rent: "<<currentRental.GetTotalrent()<<endl;
        
    Motorbike dream(2, "Honda", "125CC 2026", 1100);
    cout << "\nRentalSystem stored "
         << rentalSystem.getVehicles().size() << " vehicle, "
         << rentalSystem.getCustomers().size() << " customer, and "
         << rentalSystem.getRentals().size() << " rental." << endl;
        cout<<"\nBike id: "<<dream.getID()
            <<"\nBike Brand: "<<dream.Getbrand()
            <<"\nBike model: "<<dream.GetModel()
            <<"\nBike Rent: "<<dream.GetRent()
            <<"\nIs Bike available: "<<(dream.isAvailable() ? "true" : "false" )<<endl;

    ofstream customerFile("customer.txt", ios::app);
    ofstream rentalFile("rental.txt", ios::app);
    ofstream vehicleFile("vehicle.txt", ios::app);
    ofstream rentalSystemFile("RentalSystem.txt", ios::app);

    if (!customerFile || !rentalFile || !vehicleFile)
    {
        cerr << "Error: could not open one or more data files." << endl;
        return 1;
    }

    customerFile << "Customer ID: " << muhammad.GetID()
                 << "\nName: " << muhammad.Getname()
                 << "\nCNIC: " << muhammad.Getcnic()
                 << "\nPhone: " << muhammad.Getphone()
                 << "\nAddress: " << muhammad.Getaddress()
                 << "\n\n";

    rentalFile << "Rental ID: " << currentRental.GetRentalID()
               << "\nCustomer ID: " << currentRental.GetCustomerID()
               << "\nVehicle ID: " << currentRental.GetVehicleID()
               << "\nDuration in days: " << currentRental.GetDuration()
               << "\nRent per day: " << currentRental.GetRentperDay()
               << "\nTotal rent: " << currentRental.GetTotalrent()
               << "\n\n";

    vehicleFile << "Vehicle ID: " << civic.getID()
                << "\nBrand: " << civic.Getbrand()
                << "\nModel: " << civic.GetModel()
                << "\nRent per day: " << civic.GetRent()
                << "\nAvailable: " << (civic.isAvailable() ? "true" : "false")
                <<"\nNumber of seats: " << civic.GetSeats()
                <<"\n\n";

    if (!customerFile || !rentalFile || !vehicleFile)
    {
        cerr << "Error: could not write all data to the text files." << endl;
        return 1;
    }

    return 0;
}