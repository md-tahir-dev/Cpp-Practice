#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 4, 5, 2, 3, 4, 8, 9, 10, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int bestStart = 0, bestLen = 1;
    int currStart = 0, currLen = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currLen++;
        } else {
            currStart = i;
            currLen = 1;
        }

        if (currLen > bestLen) {
            bestLen = currLen;
            bestStart = currStart - bestLen + 1; 
        }
    }

    cout << "Longest run: ";
    for (int i = bestStart; i < bestStart + bestLen; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Length = " << bestLen << endl;

    return 0;
}
