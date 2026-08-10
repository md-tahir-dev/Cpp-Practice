#include <iostream>
using namespace std;

int largestDigit(int n)
{
    if (n < 10)
    {
        return n;
    }
    int lastDigit = n % 10;
    int largest = largestDigit(n / 10);
    if (lastDigit > largest)
    {
        return lastDigit;
    }
    else
    {
        return largest;
    }
}
int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Largest digit is: " << largestDigit(n);

    return 0;
}