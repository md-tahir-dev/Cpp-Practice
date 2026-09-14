// Write a program to: 1. Take a sentence from user. 2. Save it to a file named "data.txt". 3. Read the same file and display the content on screen
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string line;
    cout<<"Enter a line: ";
    getline(cin,line);
    cout<<endl;
    ofstream out("data.txt");
    if(!out.is_open())
    {
        cout<<"Could not open/create the file";
        return 1;
    }
    out<<line;
    out.close();
    ifstream in("data.txt");
    if(!in.is_open())
    {
        cout<<"Could not open/create the file";
        return 1;
    }
    string content;
    getline(in,content);
    cout<<"content is \""<<content<<"\"";
    in.close();
    return 0;
}