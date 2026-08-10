#include<iostream>
using namespace std;

void FIB(int n, int pre1 = 1, int pre2 = 0)
{
    if(n <= 0)
    {
        cout << "Re-enter number greater than 0";
        return;
    }

    cout << pre2 << " ";

    FIB(n - 1, pre2, pre1 + pre2);
}

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;
    if(cin.fail())
    {
        cout << "Kindly enter an integer";
        return 0;
    }
    FIB(n);
}