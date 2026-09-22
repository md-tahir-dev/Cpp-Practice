#include <iostream>
using namespace std;
void secondFreq(int arr[],int size)
{
    int freq[size] = {0};
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }
    int firstFREQ = 0;
    for (int i = 0; i < size; i++)
    {
        if (freq[i] > firstFREQ)
        {
            firstFREQ = freq[i];
        }
    }
    int secondFREQ = 0;
    for (int i = 0; i < size; i++)
    {
        if (freq[i] > secondFREQ && freq[i] < firstFREQ)
        {
            secondFREQ = freq[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (freq[i] == secondFREQ)
        {
            cout << "Second most freq element: " << i << endl;
        }
    }
}
int main()
{
    int arr[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    secondFreq(arr,size);
    return 0;
}