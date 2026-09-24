#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr={1,2,3,4,5};
    vector<int> arr1(arr);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.pop_back();
    for (int x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for (int x:arr1)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    cout<<*(arr.end());
    // cout<<"Element at 2 "<<arr[2]<<" or "<<arr.at(2);
    return 0;
}