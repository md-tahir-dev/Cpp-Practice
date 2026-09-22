// Print N to 1
#include <iostream>
using namespace std;

void print(int n,int m=1)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    print(n=n-1,m);
}
int main()
{
    int n = 5; 
    print(n);
    return 0;
}