// n factorical like 5! is 120 
#include <iostream>
using namespace std;

int factorical(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n * factorical(n-1);
    // cout<<n<<endl;
}
int main ()
{
    int n = 5;
    cout<<factorical(n);
}