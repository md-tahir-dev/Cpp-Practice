#include <iostream>

using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};
    cout << arr[5];  // ❌ undefined behavior
    cout<<endl;
    cout<<"Next!!!"<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    return 0;
}