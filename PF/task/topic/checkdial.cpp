#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i + 1 << " elements:" << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "\tEnter element " << j + 1 << " : ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nMatrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
    bool isDiagonal = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                isDiagonal = false;
            }
        }
    }
    if (isDiagonal)
        cout << "\nIt is a Diagonal matrix!";
    else
        cout << "\nIt is NOT a Diagonal matrix!";

    bool isIdentity = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                isIdentity = false;
            }
            if (i != j && matrix[i][j] != 0)
            {
                isIdentity = false;
            }
        }
    }
    if (isIdentity)
        cout << "\nIt is an Identity matrix!";
    else
        cout << "\nIt is NOT an Identity matrix!";

    return 0;
}