#include<iostream>
using namespace std;
int countofdigits(int n)
{
    if (n == 0) {
        return 0;
    }
    int count=0;
    return 1 + countofdigits(n / 10);
    cout<<count;

}
int main()
{ 
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"count of digit is "<<countofdigits(n);
}