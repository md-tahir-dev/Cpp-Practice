// Write a program using pointers and a function to swap two numbers without using a third variable.
#include <iostream>

using namespace std;
void swap(int *a, int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int main()
{
    int a = 1,b=2;
    swap(&a,&b);
    cout<<"val of a is "<<a<<" val of b is "<<b;
    return 0;
}