#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line = "This line is from another file.";
    ofstream out("sample.txt");
    out <<line; 
    return 0;
}