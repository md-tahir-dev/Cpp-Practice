#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, -2, 5, -1, 6, -3, 2, 7, -5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = arr[0];
    int currSum = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < size; i++) {
        if (currSum + arr[i] < arr[i]) {
            currSum = arr[i];
            tempStart = i;   // reset start index
        } else {
            currSum += arr[i];
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Max sum subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Maximum Sum = " << maxSum << endl;

    return 0;
}
