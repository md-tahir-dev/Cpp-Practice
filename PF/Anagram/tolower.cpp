#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char tolower1(char c)
{
    if(c>='A'&&c<='Z')
    {
        c=c+32;
        return c;
    }
}
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
