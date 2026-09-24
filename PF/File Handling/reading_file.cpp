#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("test.txt");
    string line;
    while (getline(in, line)) 
    {
        cout << line << endl;
    }
    in.close();

    return 0;
}