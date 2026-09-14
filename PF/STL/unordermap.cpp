#include <iostream>
#include<map>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map <string,int> m;
    m.emplace("camra",10);
    m.emplace("laptop",10);
    m.emplace("fridge",10);
    m.emplace("tablet",10);
    m.emplace("watch",10);
    // cout<<m.erase("camra"); 
    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    // cout<<"count of laptop "<<m["laptop"]<<endl;
    // cout<<m["camra"];
    return 0;
}