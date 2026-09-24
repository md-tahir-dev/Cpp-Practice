#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string line;
    cout<<"Enter a line: ";
    getline(cin, line);
    string word, longestWord;
    int wordCount = 0;
    stringstream ss(line);
    while (ss >> word)
    {
        wordCount++;
        if(word.size()>longestWord.size())
        {
            longestWord=word;
        }
    }
    cout<<"Word count: "<<wordCount<<endl;
    cout<<"Longest word is: "<<longestWord<<endl;
    return 0;
}