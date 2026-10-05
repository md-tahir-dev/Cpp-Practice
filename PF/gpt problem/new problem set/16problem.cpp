#include <iostream>
using namespace std;

void countSubarraysWithKOdds(int arr[], int n, int k) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        int oddCount = 0;

        for (int j = i; j < n; j++) {
            if (arr[j] % 2 != 0) { // odd number
                oddCount++;
            }

            if (oddCount == k) {
                total++;
            }
        }
    }

    cout << "Total subarrays with exactly " << k << " odd numbers = " << total << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    countSubarraysWithKOdds(arr, n, k);

    return 0;
}
