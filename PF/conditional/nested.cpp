#include <iostream>
using namespace std;

int main() {
    float marks;
    cout << "Enter marks: ";
    cin >> marks;

    if (marks >= 50) {
        if (marks >= 90) {
            cout << "Grade: A " << marks;
        } else if (marks >= 75) {
            cout << "Grade: B " << marks;
        } else {
            cout << "Grade: C " << marks;
        }
    } else {
        if (marks >= 33) {
            cout << "Grade: D " << marks;
        } else {
            cout << "Grade: F " << marks;
        }
    }
    // int x=1;
    // if (x > 0)
    //    cout << "positive\n";
    //    cout << "definitely";  // NOT part of the if! Always runs.

    return 0;
}