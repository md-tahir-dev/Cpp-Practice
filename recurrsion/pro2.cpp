// problem: print all values n to 1 like 4 to 1, example 4 3 2 1
#include<iostream>
using namespace std;
void printNUM(int n)//recursion function
{
    if(n==1)//checking that is n=1
    {
        cout<<1<<endl;//if true, print 1 
        return;
    }
    cout<<n<<endl;//printing number
    printNUM(n-1);//modifing n variable //this is called recursion
}
int main()
{
    int n = 10;
    printNUM(n);    
}