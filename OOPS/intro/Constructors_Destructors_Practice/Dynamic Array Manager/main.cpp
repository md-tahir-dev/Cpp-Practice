/*
Create a NumberArray class with private members:
- int* arr
- int size
Requirements:
1. Create a constructor that accepts the array size.
2. Allocate memory dynamically for the array.
3. Implement a function to input numbers.
4. Implement a function to display the numbers.
5. Implement a destructor that releases the allocated memory.
6. Create objects with different array sizes and test them.
Challenge: Make sure your class releases its allocated memory correctly when each object is destroyed.
*/

#include <iostream>
using namespace std;

class NumberArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    NumberArray(int s) : size(s) {
        arr = new int[size];
        cout << "Constructor: Allocated memory for " << size << " integers." << endl;
    }

    // Copy constructor (deep copy)
    NumberArray(const NumberArray& other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        cout << "Copy constructor: Deep copy created." << endl;
    }

    // Copy assignment operator (safe deep copy)
    NumberArray& operator=(const NumberArray& other) {
        if (this == &other) return *this; // self-assignment check

        // Step 1: Allocate new memory first (safe)
        int* newArr = new int[other.size];
        for (int i = 0; i < other.size; i++) {
            newArr[i] = other.arr[i];
        }

        // Step 2: Release old memory only after new allocation succeeds
        delete[] arr;

        // Step 3: Assign new memory and size
        arr = newArr;
        size = other.size;

        cout << "Assignment operator: Deep copy performed safely." << endl;
        return *this;
    }

    // Input numbers
    void inputNumbers() {
        cout << "Enter " << size << " numbers:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Display numbers
    void displayNumbers() const {
        cout << "Numbers in array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~NumberArray() {
        delete[] arr;
        cout << "Destructor: Released memory for " << size << " integers." << endl;
    }
};

int main() {
    NumberArray arr1(3);
    arr1.inputNumbers();
    arr1.displayNumbers();

    cout << "-------------------" << endl;

    // Copy constructor test
    NumberArray arr2 = arr1;  // deep copy
    arr2.displayNumbers();

    cout << "-------------------" << endl;

    // Assignment operator test
    NumberArray arr3(5);
    arr3 = arr1;  // safe deep copy assignment
    arr3.displayNumbers();

    return 0;
}
