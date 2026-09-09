// Print Array
#include<iostream>
using namespace std;
int main()
{
    int arrNUM[]={10, 20, 30, 40, 50};
    int size = sizeof(arrNUM)/sizeof(int);
    for(int i = 0; i < size; i++)
    {
        cout<<arrNUM[i]<<endl;
    }
}