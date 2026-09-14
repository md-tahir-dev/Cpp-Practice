#include <iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map <string,int> m;
    m["tv"]=100;
    m["laptop"]=50;
    m["headphones"]=25;
    m["tablet"]=125;
    m["watch"]=45;
    m.emplace("camra",10);
    cout<<m.erase("tv"); 
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"count of laptop "<<m["laptop"]<<endl;
    cout<<m["camra"];
    return 0;
}