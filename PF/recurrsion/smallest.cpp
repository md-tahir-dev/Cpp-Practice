#include <iostream>
using namespace std;

int smallestDigit(int n)
{
    if (n < 10)
    {
        return n;
    }
    int smallDigit = n % 10;
    int Smallest = smallestDigit(n / 10);
    return min(smallDigit, Smallest);
}
int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Smallest digit is: " << smallestDigit(n);

    return 0;
}