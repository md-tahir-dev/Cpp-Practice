#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>arr={1,2,3,4,5};
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for (auto itr = arr.rbegin(); itr != arr.rend(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    
    return 0;
}