#include<iostream>
using namespace std;

int sumoflast(int num){
    int digitsum=0;
    while (num>0)
    {
        int lastdigit = num%10;
        num/=10;

        digitsum+=lastdigit;
    }
    
    return digitsum;
}

int main()
{
    cout<<"Sum is: "<<sumoflast(2564)<<endl;
    return 0;
}