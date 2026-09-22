#include <iostream>
#include <cmath> // Required for abs()
using namespace std;

int countDigit(int n, bool isOriginalCall = true) {
    // Convert negative numbers to positive only on the initial call
    if (isOriginalCall) {
        n = abs(n);
        
        // Handle original input of 0 explicitly
        if (n == 0) {
            return 1;
        }
    }
    
    // Base Case for subsequent recursion steps
    if (n == 0) {
        // breaks recursion loop when digits are fully divided down
        return 0; 
    }
    
    // Pass false to ensure inner steps do not repeat the initialization logic
    return 1 + countDigit(n / 10, false);
}

int main() {
    int n1 = 0;
    cout << "Input: " << n1 << " -> Count: " << countDigit(n1) << endl;

    int n2 = -12345;
    cout << "Input: " << n2 << " -> Count: " << countDigit(n2) << endl;

    int n3 = 7;
    cout << "Input: " << n3 << " -> Count: " << countDigit(n3) << endl;

    return 0;
}
