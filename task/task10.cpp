#include <iostream>
using namespace std;

int main()
{
    int row = 6;
    int col = 11;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == 5 - i || j == 5 + i)
            {
                cout << "* ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << endl;
    }

    return 0;
}