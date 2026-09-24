#include<iostream>
#include<algorithm>    
#include<string>
#include"tolower.h"
using namespace std;
int main()
{
    string str1,str2;
    cout<<"Enter first word: ";
    cin>>str1;
    for(char &c:str1)
    {
        c=tolower1(c);    
    }
    cout<<"Enter second word: ";
    cin>>str2;
    for(char &c:str2)
    {
        c=tolower1(c);
    }
    if(isAnagram(str1,str2))
    {
        cout<<"Anagram";
    }
    else
    {
        cout<<"Not Anagram";
    }
    return 0;
}