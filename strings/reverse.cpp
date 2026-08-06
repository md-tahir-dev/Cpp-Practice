#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string word = "Muhammad";
    reverse(word.begin(),word.end());
    cout<<word;
}