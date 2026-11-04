#ifndef RENTAL_H
#define RENTAL_H

class Customer;
class Vehicle;

class Rental {
private:
    int rentalID;
    Customer* customer;
    Vehicle* vehicle;
    int days;
    double totalCost;
    bool returned;

public:
    Rental(int rentalID, Customer& customer, Vehicle& vehicle, int days);

    int getRentalID() const;
    int getDays() const;
    double getTotalCost() const;
    bool isReturned() const;

    void displayInfo() const;
    void markReturned();
};

#endif
