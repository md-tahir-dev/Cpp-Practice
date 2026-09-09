#include<iostream>
using namespace std;
int countWORD(string str) {
    int count = 0;
    bool insideWord = false;

    for (char c : str) {
        if (c != ' ') {
            if (!insideWord) {
                count++;
                insideWord = true;
            }
        } else {
            insideWord = false;
        }
    }
    return count;
}
int main()
{
    string str;
    cout<<"Enter your name: ";
    getline(cin,str);
    cout<<countWORD(str);
    return 0;
}