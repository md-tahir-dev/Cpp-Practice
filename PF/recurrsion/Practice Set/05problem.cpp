// Power
#include <iostream>

using namespace std;
int power(int a,int b)
{
   if(b==0)
   {
    return 1;
   }
    return a*power(a,b-=1);
}
int main()
{
    int a=2,b=5;
    cout<<power(a,b);
    return 0;
}