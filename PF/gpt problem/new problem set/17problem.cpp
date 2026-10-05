#include <iostream>

using namespace std;
void fun(int arr[], int size)
{
    int maxLen = 0, startInd = -1, endInd = -1, counteven = 0, countodd = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] % 2==0)
            {
                counteven++;
            }
            else if (arr[j] % 2!=0)
            {
                countodd++;
            }
            if (counteven == countodd)
            {
                int lenght = j - i + 1;
                if (lenght > maxLen)
                {
                    maxLen = lenght;
                    startInd = i;
                    endInd = j;
                }
            }
        }
        counteven = 0, countodd = 0;
    }
    for (int a = startInd; a <= endInd; a++)
    {
        cout << arr[a] << " ";
    }
    cout << endl;
    cout << "Length = " << maxLen << endl;
    cout << "Count of even = " << maxLen / 2 << endl;
    cout << "Count of odd = " << maxLen / 2 << endl;
}
int main()
{
    int arr[] = {2, 1, 4, 3, 6, 8, 5, 7, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, size);
    return 0;
}