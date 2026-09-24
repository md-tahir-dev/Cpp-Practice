#include <iostream>
using namespace std;

void update(int* p) {
    *p = 50;   // modifies original variable
}

int main() {
    int x = 10;
    update(&x);
    cout << x;  // prints 50
}
