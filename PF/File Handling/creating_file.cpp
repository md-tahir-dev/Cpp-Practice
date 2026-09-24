#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream out("test.txt");
    if (!out) 
    {
        cout << "Error creating file!";
        return 1;
    }
    out << "Hello,"<<endl<<" World!" << endl;
    out.close();

    return 0;
}