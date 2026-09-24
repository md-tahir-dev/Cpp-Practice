/*
Problem: Matrix Analyzer

Write a C++ program that performs different operations on a 2D array (matrix).

Input
Read the number of rows r and columns c.
Read all the elements of the matrix.
Create the following functions:
1. printMatrix()

Print the matrix in row and column format.

2. findLargest()

Return the largest element in the matrix.

3. findSmallest()

Return the smallest element in the matrix.

4. countEvenOdd()

Count and display:

Total even numbers
Total odd numbers
5. sumOfDiagonal()

If the matrix is square (r == c):

Print the sum of the main diagonal.
Otherwise print:
Diagonal does not exist.
6. searchElement()

Ask the user for a target value.

If found, print:
Found at Row = x Column = y
Otherwise print:
Element not found.
Example Input
3 3

2 5 8
7 9 1
4 6 3

Target = 6
Output
Matrix:
2 5 8
7 9 1
4 6 3

Largest = 9
Smallest = 1

Even = 4
Odd = 5

Diagonal Sum = 14

Found at Row = 2 Column = 1
Concepts You'll Practice
✅ if, else if, else
✅ for loops (nested loops)
✅ 2D arrays
✅ Functions with parameters
✅ Functions returning values
✅ Linear search in a matrix
✅ Traversing rows and columns
Rules
❌ Don't use vectors.
❌ Don't use classes.
❌ Don't use STL algorithms like max() or min().
✅ Use only functions, loops, conditions, and a normal 2D array.
*/
#include<iostream>
#include<climits>
using namespace std;
void printMatrix(int r, int c, int** arr)
{
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return; 
}
void findLargest(int r, int c, int** arr)
{
    int large = INT_MIN;
    for(int i = 0; i<r; i++)
    {   
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]>large)
            large=arr[i][j];
        }
    }
        cout<<"Largest = "<<large;
}
void findSmallest(int r, int c, int** arr)
{
    int small = INT_MAX;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c;j++)
        {
            if(arr[i][j]<small)
            {
                small=arr[i][j];
            }
        }
    }
        cout<<"Smallest = "<<small;
}
void countevenodd(int r, int c, int** arr)
{
    int countodd = 0;
    int counteven = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(arr[i][j]%2==0)
            {
                counteven++;
            }
            else
            {
                countodd++;
            }
        }
        
    }
    cout<<"Even = "<<counteven;
    cout<<endl;
    cout<<"Odd = "<<countodd;
}
void sumOfDiagonal(int r, int c, int** arr)
{
    int sum=0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(i==j)
            {
                sum += arr[i][j];
            }
        }
        
    }
    cout<<"Diagonal Sum = "<<sum;
}
void searchElement(int r, int c, int** arr, int target)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(arr[i][j]==target)
            {
                cout<<"Found at Row = "<<i<<" Column = "<<j;
                return;
            }
        }
        
    }
    cout << "Element not found.";
}
int main()
{
    int r, c;
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;
    int target;
    int** arr = new int*[r];
    for (int i = 0; i < r; ++i) {
        arr[i] = new int[c]; 
    }
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c;j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    cout<<"Enter target = ";
    cin>>target;
    printMatrix(r,c,arr);
    cout<<endl;
    findLargest(r,c,arr);
    cout<<endl;
    findSmallest(r,c,arr);
    cout<<endl;
    cout<<endl;
    countevenodd(r,c,arr);
    cout<<endl;
    if(r==c)
    {
        sumOfDiagonal(r,c,arr);
    }
    else
    {
        cout<<"Diagonal does not exist.";
    }
    cout<<endl;
    searchElement(r,c,arr,target);
    for(int i = 0; i < r; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}