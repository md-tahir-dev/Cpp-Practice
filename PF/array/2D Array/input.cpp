// Gerenal code of taking iput in 2D Array
#include<iostream>
using namespace std;

int main()

{
    int matix[4][3];
    int rows = 4;
    int cols = 3;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j<cols;j++)
        {
            cout<<"Enter 12 number with space: ";
            cin>>matix[i][j];
        }
    }
    cout<<endl;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j<cols;j++)
        {
            cout<<matix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}