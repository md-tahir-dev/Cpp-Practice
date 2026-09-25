#include <iostream>
using namespace std;
void fun(int arr[], int size, int k)
{
    int bestStart = -1, bestEnd = -1;
    int minLen = size + 1;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum >= k)
            {
                int length = j - i + 1;
                if (length < minLen)
                {
                    minLen = length;
                    bestStart = i;
                    bestEnd = j;
                }
            }
        }
    }
    for (int i = bestStart; i <= bestEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"\nMin Length is "<<minLen<<endl;
}

int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int k = 7;
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, size, k);
    return 0;
}
// output should be 4,3 because we are finding shortest Smallest Subarray With Sum with K