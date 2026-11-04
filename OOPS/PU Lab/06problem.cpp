#include <iostream>
#include <string>
#include <vector>
using namespace std;
class StringFormatter
{
private:
    string line;

public:
    StringFormatter(string line)
        : line(line) {}

    void print()
    {
        cout << line;
    }
    void printRightAligned(int n)
    {
        if (n <= 0)
        {
            return;
        }
        {
            for (int i = 0; i < line.length(); i += n)
            {
                string chunk = line.substr(i, n);
                int space = n - chunk.length();
                for (int j = 0; j < space; j++)
                {
                    cout << " ";
                }
                cout << chunk << endl;
            }
        }
    }
};
int main()
{
    StringFormatter name("The world is indeed full of peril and in it there are many dark places. But still there is much that is fair. And though in all lands, love is now mingled with grief, it still grows, perhaps, the greater");
    name.printRightAligned(20);

    return 0;
}