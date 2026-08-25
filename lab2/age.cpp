#include <iostream>
using namespace std;

int main() {
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;

    cout << "Enter your date of birth : ";
    cin >> birthDay >> birthMonth >> birthYear;

    cout << "Enter the current date : ";
    cin >> currentDay >> currentMonth >> currentYear;

    if (birthDay < 1 || birthDay > 30 ||
        currentDay < 1 || currentDay > 30 ||
        birthMonth < 1 || birthMonth > 12 ||
        currentMonth < 1 || currentMonth > 12 ||
        birthYear < 1 || currentYear < 1 ||
        birthYear > currentYear) {

        cout << "Invalid date entered." << endl;
        return 1;
    }
    long long birthDays =
        birthYear * 365 + (birthMonth - 1) * 30 + (birthDay - 1);

    long long currentDays =
        currentYear * 365 + (currentMonth - 1) * 30 + (currentDay - 1);

    if (currentDays < birthDays) {
        cout << "The current date cannot be before the date of birth."
             << endl;
        return 1;
    }
    long long totalDays = currentDays - birthDays;
    int years = totalDays / 365;
    totalDays = totalDays % 365;

    int months = totalDays / 30;
    int days = totalDays % 30;

    cout << "\nYour age is "
         << years << " years, "
         << months << " months, and "
         << days << " days." << endl;

    return 0;
}
