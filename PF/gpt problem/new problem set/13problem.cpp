#include <iostream>
using namespace std;

void longestSubarraySumLessThanK(int arr[], int n, int k) {
    int bestStart = -1, bestEnd = -1;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum < k) {
                int length = j - i + 1;
                if (length > maxLen) {
                    maxLen = length;
                    bestStart = i;
                    bestEnd = j;
                }
            } else {
                break;
            }
        }
    }

    if (bestStart != -1) {
        cout << "Longest subarray with sum < " << k << ": ";
        for (int i = bestStart; i <= bestEnd; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nLength = " << maxLen << endl;
    } else {
        cout << "No subarray found." << endl;
    }
}

int main() {
    int arr[] = {2, 1, 3, 2, 1, 1, 4};
    int k = 7;
    int n = sizeof(arr)/sizeof(arr[0]);

    longestSubarraySumLessThanK(arr, n, k);

    return 0;
}
