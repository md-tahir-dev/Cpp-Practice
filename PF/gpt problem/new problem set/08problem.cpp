#include <iostream>
using namespace std;
void fun(int arr[], int k, int size)
{
    int maxLen = 0;
    int bestStart = -1, bestEnd = -1;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                int length = j - i + 1;
                if (length > maxLen)
                {
                    maxLen = length;
                    bestEnd = j;
                    bestStart = i;
                }
            }
        }
    }
    if (maxLen > 0)
    {
        for (int i = bestStart; i <= bestEnd; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nMax Length is " << maxLen << endl;
    }
    else
    {
        cout << "No subarray found with sum " << k << endl;
    }
}
int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2, 1, 4};
    int k = 8;
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, k, size);
    return 0;
}