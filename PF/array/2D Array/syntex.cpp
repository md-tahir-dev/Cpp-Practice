// Gerenal code 
#include<iostream>
using namespace std;

int main()

{
    int matix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int rows = 4;
    int cols = 3;
    // matix [1][2]=18;
    // cout<<matix [1][2];
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j<cols;j++)
        {
            cout<<matix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}