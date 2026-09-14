#include <iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    multimap <string,int> m;
    m.emplace("camra",10);
    m.emplace("camra",10);
    m.emplace("camra",10);
    m.emplace("camra",10);
    m.emplace("camra",10);
    cout<<m.erase("camra"); 
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    // cout<<"count of laptop "<<m["laptop"]<<endl;
    // cout<<m["camra"];
    return 0;
}