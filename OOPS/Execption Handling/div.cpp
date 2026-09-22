#include <iostream>
using namespace std;

int divide(int x, int y) {
    if (y == 0) {
        throw "Cannot divide by zero.";
    }
    return x / y;
}

int main() {
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    try {
        int result = divide(x, y);
        cout << "Result: " << result << '\n';
    } 
    catch (const char *statement) {
        cout << statement << '\n';
    }

    return 0;
}
