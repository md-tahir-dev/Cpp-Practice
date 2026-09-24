#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {12, 5, 8, 20, 15, 20, 3};

    int largest = arr[0];
    int secondLargest = arr[1];

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;

    return 0;
}