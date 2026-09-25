#include <iostream>

using namespace std;
void fun(int arr[], int size)
{
    int maxLen = 0, startInd = -1, endInd = -1, countzero = 0, countone = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] == 0)
            {
                countzero++;
            }
            else if (arr[j] == 1)
            {
                countone++;
            }
            if (countone == countzero)
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
        countzero = 0, countone = 0;
    }
    for (int a = startInd; a <= endInd; a++)
    {
        cout << arr[a] << " ";
    }
    cout << endl;
    cout << "Length = " << maxLen << endl;
    cout << "Count of 0s = " << maxLen / 2 << endl;
    cout << "Count of 1s = " << maxLen / 2 << endl;
}
int main()
{
    int arr[] = {0, 1, 0, 0, 1, 1, 0, 1, 1};
    int size = sizeof(arr) / sizeof(0);
    fun(arr, size);
    return 0;
}