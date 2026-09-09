#include <iostream>
using namespace std;
void Pattern(int rows,int startnum)
{
    int i = 1;
    while (i<=rows)
    {
        int count= 2 * i-1;
        int s = rows-i;
        while (s>0)
        {
            cout<<"   ";
            s--;
        }
        
        int j = 1;
        while (j<=count)
        {
            cout<<startnum<<" ";
            startnum++;
            j++;
        }
        cout<<endl;
        i++;
    }
    
}
int main()
{
    int n; 
    cout<<"Enter number: ";
    cin>>n;
    int startnum;
    cout<<"Enter the starting number: ";
    cin>>startnum;
    Pattern(n,startnum);

    return 0;
}