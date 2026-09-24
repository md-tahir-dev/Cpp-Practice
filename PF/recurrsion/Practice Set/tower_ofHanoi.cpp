// #include <iostream>
// using namespace std;
// void tow(int n,string source,string helper, string destination)
// {
//     if(n==0)
//     {
//         return;
//     }
//     tow(n-1,source,destination,helper);
//     cout<<"Move Plate "<<n<<" from "<<source<<" to "<<destination<<endl;
//     tow(n-1,helper,source,destination);
// }
// int main()
// {
//     int n = 3;
//     tow(n,"Rod A","Rod B","Rod C");
//     return 0;
// }

#include <iostream>

using namespace std;
void moveDisk(char from, char to, int disk)
{
    cout << "Move plate " << disk << " from " << from << " to " << to << endl;
}
int main()
{
    int n;
    cout << "Enter the number of plates: ";
    cin >> n;
    int moves = (1 << n) - 1;
    char source = 'A', hepler = 'B', destination = 'C';
    if (n % 2 == 0)
    {
        swap(destination, hepler);
    }
    for (int i = 1; i <= moves; i++)
    {
        int disk = 1;
        while (i % (2 * disk) == 0)
        {
            disk++;
        }
        if (disk == 1)
        {
            if (n % 2 == 1)
            {
                if (i % 3 == 1)
                {
                    moveDisk(source, destination, disk);
                }
                else if (i % 3 == 2)
                {
                    moveDisk(source, hepler, disk);
                }
                else
                {
                    moveDisk(hepler, destination, disk);
                }
            }
            else
            {

                if (i % 3 == 1)
                {
                    moveDisk(source, hepler, disk);
                }
                else if (i % 3 == 2)
                {
                    moveDisk(source, destination, disk);
                }
                else
                {
                    moveDisk(hepler, destination, disk);
                }
            }
        }
        else
        {
            if (i % 3 == 1)
            {
                moveDisk(source, destination, disk);
            }
            else if (i % 3 == 2)
            {
                moveDisk(source, hepler, disk);
            }
            else
            {
                moveDisk(hepler, destination, disk);
            }
        }
    }
    return 0;
}