// Write a program in C++ which opens a file called Numbers.txt (consisting of numbers, a sample is provided, and you can add more numbers to it if you like) and reads the list of integers present in it. If the number being read is an odd number then it writes it in a file called odd.txt and if the number is even it writes it in file called even.txt. At the end your program should display the number of odd numbers written in the odd.txt file and the number of even numbers written in the even.txt file.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("Numbers.txt");
    ofstream oddFile("odd.txt");
    ofstream evenFile("even.txt");

    if (!inputFile) {
        cout << "Error: Could not open Numbers.txt" << endl;
        return 1;
    }

    int num;
    int oddCount = 0, evenCount = 0;

    while (inputFile >> num) {
        if (num % 2 == 0) {
            evenFile << num << " ";
            evenCount++;
        } else {
            oddFile << num << " ";
            oddCount++;
        }
    }

    inputFile.close();
    oddFile.close();
    evenFile.close();

    cout << "Total odd numbers written: " << oddCount << endl;
    cout << "Total even numbers written: " << evenCount << endl;

    return 0;
}
