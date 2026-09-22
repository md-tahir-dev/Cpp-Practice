// Print 1 to N
#include <iostream>

using namespace std;
void print(int n,int m = 1)
{
    if(n==0)
    {
        return;
    }
    if(m>n)
    {
        return;
    }
    cout<<m<<endl;
    print(n,m+=1);
}
int main()
{
    int n=5;
    print(n);
    return 0;
}