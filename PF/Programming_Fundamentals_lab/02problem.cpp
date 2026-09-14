// Write a C program to check if a given string is a palindrome (e.g., madam, racecar). Don't use
// strrev().
#include<iostream>
#include<string>
#include <cctype>
using namespace std;

void reverseString(string word,string copystr, int lenght)
{
    for(int ch: word)
    {
        lenght++;
    }
    int start = 0;
    int end = lenght-1;
    while(start<end)
    {
        swap(word[start],word[end]);
        start++;
        end--;
    }
    if(word==copystr)
    {
        cout<<"Your entered word is palindrome.";
    }
    else
    {
        cout<<"Your entered word isn't palindrome.";
    }
}
int main()
{
    string word;
    cout<<"Enter a Palindrome word: ";
    cin>>word;
    string copystr = word;
    int lenght=0;
    reverseString(word,copystr,lenght);
}