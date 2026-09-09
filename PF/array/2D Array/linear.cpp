// for find specific element
// Gerenal code of taking iput in 2D Array
#include<iostream>
using namespace std;
bool linearSEARCH(int matix[][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(matix[i][j]==target)
            {
                return true;
            }
        }
        
    }
    return false;
}
int searchCELL(int matix[3][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(matix[i][j]==target)
            {
                cout<<i<<","<<j;
                return 0;
            }
        }
        
    }
    cout<<"-1,1";
    return 0;
}
int main()

{
    int matix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;
    int target;
    cin>>target;
    cout<<linearSEARCH(matix,rows,cols,target);
    cout<<endl;
    searchCELL(matix,rows,cols,target);
}