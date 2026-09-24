#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr={1,7,4,3,6};
    reverse(arr.begin()+1,arr.begin()+3);
    for (auto i : arr)
    {
        cout<<i<< " ";
    }
    cout<<endl;
    return 0;
}