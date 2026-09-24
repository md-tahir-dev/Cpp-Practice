#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream in("sample1.txt");
    getline(in,line);//just like cin
    cout<<line;
    return 0;
}