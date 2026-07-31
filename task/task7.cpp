#include <iostream>
using namespace std;
int main()
{
    int rows = 8;
    int cols = 24;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 1 || i == rows-1 || j == 1 || j == cols-1)
            {
                cout << "=";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}