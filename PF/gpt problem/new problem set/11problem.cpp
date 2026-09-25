#include <iostream>

using namespace std;
void fun(int arr[], int size)
{
    int bestStart = 0, bestEnd = 0;
    int bestProduct = arr[0];
    for (int i = 0; i < size; i++)
    {
        int Product = 1;
        for (int j = i; j < size; j++)
        {
            Product *= arr[j];
            if (Product > bestProduct)
            {
                bestProduct = Product;
                bestStart = i;
                bestEnd = j;
            }

        }
    }
    for (int i = bestStart; i <= bestEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nMax product is " << bestProduct << endl;
}
int main()
{
    int arr[] = {2, 3, -2, 4, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, size);
    return 0;
}