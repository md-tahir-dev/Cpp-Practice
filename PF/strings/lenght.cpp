#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[]="Muhammad Tahir";
    int lenght = 0;
    int lenght1 = 0;
    for(char ch:str)
    {
        lenght++;
    }
    for(int i = 0; i<str[i] != '\0';i++)
    {
        lenght1++;
    }
    cout<<strlen(str);
    cout<<endl;
    cout<<lenght;
    cout<<endl;
    cout<<lenght1;
    cout<<endl;
    string school="City Cadet School";
    cout<<school.length();
}