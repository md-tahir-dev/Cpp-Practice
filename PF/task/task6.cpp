#include<iostream>
using namespace std;
int main()
{
    double sum = 0;
    int n;
    cout<<"Enter a postive integer N: ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Re-enter the value of N";
        return -1;
    } 
    else{
    cout << "Series: ";
    for(int i = 0; i < n; i++)
    {
        cout << "1/" << 2 * i;

        if(i != n)
            cout << " + ";
        sum += 1 / (2 * i);
    }
    cout<<endl;
    cout << "Sum = " << sum;

    return 0;
    }
}