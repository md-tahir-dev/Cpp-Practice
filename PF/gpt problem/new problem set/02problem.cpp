#include <iostream>
using namespace std;

void missNumber(int arr[], int size)
{
    int N = size + 1;
    int expectedSum = N * (N + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < size; i++)
    {
        actualSum += arr[i];
    }
    int missing = expectedSum - actualSum;
    cout << "Missing number is " << missing << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    missNumber(arr, size);
    return 0;
}
