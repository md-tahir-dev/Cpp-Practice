/*
Write a program to calculate students’ average test scores and their grades.
You may assume the following input data:

Johnson 85 83 77 91 76
Aniston 80 90 95 93 48
Cooper 78 81 11 90 73
Gupta 92 83 30 69 87
Blair 23 45 96 38 59
Clark 60 85 45 39 67
Kennedy 77 31 52 74 83
Bronson 93 94 89 77 97
Sunny 79 85 28 93 82
Smith 85 72 49 75 63
Use three arrays:

A one-dimensional array to store the students’ names

A (parallel) two-dimensional array to store the test scores

A parallel one-dimensional array to store grades

Your program must contain at least the following functions:

A function to read and store data into two arrays

A function to calculate the average test score and grade

A function to output the results
*/

#include <iostream>
#include <string>
using namespace std;
const int NUM_STUDENT = 10;
const int NUM_TEST = 5;
void readData(string name[],double score[NUM_STUDENT][NUM_TEST])
{
    for (size_t i = 0; i < NUM_STUDENT; i++)
    {
        // cout<<"Enter your name: ";
        cin>>name[i];
        for (size_t j = 0; j < NUM_TEST; j++)
        {
            cin>>score[i][j];
        }
    }
}
void computeAverage(double avarage[],double score[NUM_STUDENT][NUM_TEST],char grade [NUM_STUDENT])
{
    for (size_t i = 0; i < NUM_STUDENT; i++)
    {   
        int sum = 0;
        for (size_t j = 0; j < NUM_TEST; j++)
        {
            sum+=score[i][j];
        }
        avarage[i] = double(sum)/NUM_TEST;
        if(avarage[i]>=90)
        {
            grade[i]='A';
        }
        else if(avarage[i]>=80)
        {
            grade[i]='B';
        }
        else if(avarage[i]>=70)
        {
            grade[i]='C';
        }
        else if(avarage[i]>=60)
        {
            grade[i]='D';
        }
        else if(avarage[i]>=50)
        {
            grade[i]='E';
        }
        else
        {
            grade[i]='F';
        }
        }
}
void print(string name[NUM_STUDENT],char grade[NUM_STUDENT],double avarage[NUM_STUDENT])
{
    double classSUM=0;
    for (size_t i = 0; i < NUM_STUDENT; i++)
    {
        cout<<name[i]<<"'s avarage: "<<avarage[i]<<" grade: "<<grade[i]<<endl;
        classSUM+=avarage[i];
    }
    cout<<"The average of class is: "<<classSUM/NUM_STUDENT<<endl;
}
int main()
{
    string name[NUM_STUDENT];
    double score[NUM_STUDENT][NUM_TEST];
    char grade[NUM_STUDENT];
    double avarage[NUM_STUDENT];
    readData(name,score);
    computeAverage(avarage,score,grade);
    print(name,grade,avarage);    
    return 0;
}