#include <iostream>

using namespace std;

int main()
{
    int n = 3;
    int moves = (1 << n) - 1;
    for (int i = 1; i <= moves; i++)
    {
        int disk = 1;
        while (i % (2 * disk) == 0)
        {
            disk++;
        }
        if (n % 2 == 1)
        {
            if (i % 3 == 1)
            {
                cout << "Move plate " << disk <<" move "<< " A to C" << endl;
            }
            else if (i % 3 == 2)
            {
                cout << "Move plate " << disk <<" move "<< " A to B" << endl;
            }
            else
            {
                cout << "Move plate " << disk <<" move "<< " B to C" << endl;
            }
        }
        else
        {

            if (i % 3 == 1)
            {
                cout << "Move plate " << disk <<" move "<< " A to B" << endl;
            }
            else if (i % 3 == 2)
            {
                cout << "Move plate " << disk <<" move "<< " A to C" << endl;
            }
            else
            {
                cout << "Move plate " << disk <<" move "<< " B to C" << endl;
            }
        }
    }
    return 0;
}