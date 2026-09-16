// 1,5,70,90,2,3,4
//  contiune array is 2 3 4
//  largest number is 4
#include <iostream>
#include <vector>
using namespace std;
vector<int> Coutiunous(int arr[], int size)
{
    vector<int> result;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            if (result.empty())
            {
                result.push_back(arr[i - 1]);
            }
            result.push_back(arr[i]);
        }
    }
    return result;
}
void largest(vector<int> large, int size)
{
    int large_ele = large[0];
    for (int i = 1; i < size; i++)
    {
        if (large[i] > large_ele)
        {
            large_ele = large[i];
        }
    }
    cout << "Largest element is: " << large_ele;
}
int main()
{
    int arr[] = {1, 5, 70, 90, 2, 3, 4, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> conARR = Coutiunous(arr, size);
    int size2 = sizeof(conARR) / sizeof(conARR[0]);
    cout << "Contiunous Array is: ";
    for (int num : conARR)
    {
        cout << num << " ";
    }
    cout << endl;

    largest(conARR, size2);
    return 0;
}
// input array 1,5,70,90,2,3,4
// output continue array 2,3,4
// than will find largest from continue array
// make copy of index 0 like 1 it will find 2 for index 1 if it doesn't find 2,false  then go for next 5 for it finds 6, same it will store 2 3 4 when true
