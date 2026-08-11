#include "functions.h"
#include <algorithm>

using namespace std;

int largestDigit(int n)
{
    if (n < 10)
    {
        return n;
    }

    int digit = n % 10;

    int largest = largestDigit(n / 10);

    return max(digit, largest);
}