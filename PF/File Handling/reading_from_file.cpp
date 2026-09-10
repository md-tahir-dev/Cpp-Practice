#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ifstream in("write_file.txt");
    if(in.is_open())
    {
        cout<<"File opened successfully"<<endl;
        while (getline(in,line))
        {
            cout<<line<<endl;
        }
        in.close();
        cout<<"File read and closed successfully.\n";
    }
    else
    {
        cout << "File could not be opened";
    }
    return 0;
}