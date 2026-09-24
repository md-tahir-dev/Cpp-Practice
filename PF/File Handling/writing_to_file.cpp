#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ofstream out("write_file.txt",ios::app);
    out << "Hello";
    out.close();
    ifstream in("write_file.txt");
    if(in.is_open())
    {
        while (getline(in,line))
        {
            cout << line<<endl;
        }
        cout << endl;
        in.close();
        cout << "File read and closed successfully";
    }
    return 0;
}