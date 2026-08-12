#include<iostream>
#include<algorithm> 
#include <cctype>   
#include<string>
using namespace std;
bool isAnagram(string str1,string str2)
{
    if(str1.length()!=str2.length())
    {
        return false;
    }
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1==str2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str1,str2;
    cout<<"Enter first word: ";
    cin>>str1;
    for(char &c:str1)
    {
        c=tolower(c);    
    }
    // cout<<str1;
    cout<<"Enter second word: ";
    cin>>str2;
    for(char &c:str2)
    {
        c=towlower(c);
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