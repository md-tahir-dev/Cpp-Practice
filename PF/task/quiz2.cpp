#include<iostream>
#include<vector>
using namespace std;
bool isPrime (int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }    
    }
    return true;
}
void seprate(int n, int digit, vector<int>& arr)
{
    while(n>0)
    {
        digit = n%10;
        arr.push_back(digit);
        n = n / 10;
    }
}
void printVEC( vector <int>& arr)
{
        for(int i = arr.size()-1; i>=0;i--)
    {
        cout<<arr[i];
        cout<<", ";
    }
}
void multi(int i, int n,vector <int>& arr ){
    int multiply=1;
    for(i = 0; i<arr.size();i++)
    {
        multiply=multiply*arr[i];
    }
    cout<<"The number is prime. Product of its digits: "<<multiply;
}
void reverse(vector<int> arr)
{
    // int i;
    cout<<"The number is even but not prime. Reversed digits: ";   
    for(int i =0; i<arr.size();i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int n;
    int sum=0;
    vector <int> arr;
    int digit,i;
    cout<<"Enter an postive integer: "; 
    cin>>n;
    if(n<=0)
    {
        cout<<"Enter a postive number";
        return -1;
    }
    if(isPrime(n))
    {
        cout<<"Prime"<<endl;
        seprate(n,digit, arr);
        printVEC(arr);
        cout<<endl;
        multi(i,n,arr);
    }
    else{
        if(n%2!=0)
        {   
            seprate(n,digit, arr);
            for(int j=0; j<arr.size();j++)
            {
                sum = sum + arr[j];
            }
        cout<<sum;
        }
        else
        {
            seprate(n,digit, arr);
            // cout<<"Not Prime";
            reverse(arr);
        }
    }
    return 0;
}