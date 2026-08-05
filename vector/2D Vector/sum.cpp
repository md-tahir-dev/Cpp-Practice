#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int SUM(vector <vector <int>> matrix, int rows, int cols)
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
    vector <vector <int>> matrix={
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    int rows = 3;
    int cols = 3;
    cout<<SUM(matrix,rows,cols);
}