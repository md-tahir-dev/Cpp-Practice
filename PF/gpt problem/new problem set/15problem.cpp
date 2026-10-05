#include <iostream>

using namespace std;
void fun(int arr[], int k, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= arr[j];
            if (product < k)
            {
                for (int a = i; a <= j; a++)
                {
                    cout << arr[a] << " ";
                }
                count++;
                cout << endl;
            }
        }
    }
    cout << "Total count of subarray is: " << count << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 2};
    int k = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    fun(arr, k, n);
    return 0;
}