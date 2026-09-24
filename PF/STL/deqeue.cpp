#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque <int>d={1,2,3,4,5};
    for(int i: d)
    {
        cout<<i<<" "<<endl;
    }
    cout<<d[2]<<endl;
    return 0;
}