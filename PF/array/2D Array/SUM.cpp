#include<iostream>
#include<climits>
using namespace std;
int SUM(int matrix[][3], int rows, int cols)
{
    int SUMmax = INT_MIN;
    for(int i = 0; i<cols;i++)
    {
        int sum1 = 0;
        for (int j = 0; j < rows; j++)
        {
            sum1 += matrix[j][i];
        }
        SUMmax=max(SUMmax,sum1);
        
    }
    return SUMmax;
}
int main()
{
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;
    cout<<SUM(matrix,rows,cols);
}