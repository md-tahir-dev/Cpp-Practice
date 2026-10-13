#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"How many values you want to store: ";
    cin >> n;
    int * ptr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter an integer for element "<<i+1<<": ";
        // cin>>ptr[i];
        cin>> *(ptr+i);
    }
    cout<<"Your entered values: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl; 
    delete [] ptr;
    ptr=nullptr;
    
    return 0;
}