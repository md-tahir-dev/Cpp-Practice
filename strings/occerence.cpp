#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        int index = s.find(part);
        s.erase(index, part.length());
    }
    return s;
}

int main()
{
    string s, part;

    cin >> s >> part;

    cout << removeOccurrences(s, part);

    return 0;
}