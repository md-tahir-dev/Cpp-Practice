#include<iostream>
#include<vector>
using namespace std;
void seprate(int input, int digit, vector<int>& arr)
{
    while(input>0)
    {
        digit = input%10;
        arr.push_back(digit);
        input = input / 10;
    }
}
void PrintVEC(vector<int>& arr)
{
    for (int i = arr.size()-1; i >= 0; i--)
    {
        // cout<<arr[i]<<" ";
    }
}
void Power_fun(int power, vector<int>& saveNUM, vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {   
        int ans = 1;
        for(int j = 0; j < power; j++)
        {
            ans *= arr[i];
        }
        saveNUM.push_back(ans);
    }
    // cout<<ans;
}
void PrintVEC1(vector<int>& saveNUM)
{
    for (int i = saveNUM.size()-1; i >= 0; i--)
    {
        // cout<<saveNUM[i]<<" ";
    }
}
void sumVec(int &sum, vector<int>& saveNUM)
{
    for (int i = 0; i < saveNUM.size(); i++)
    {
        sum += saveNUM[i];
    }
}
void check(int sum, int n)
{
    if(n==sum)
    {
        cout<<"Your entered number is narcissistic. ";
    }
    else
    {
        cout<<"Your entered number isn't narcissistic ";
    }
}
int main()
{   
    int sum = 0;
    vector<int> arr;
    vector<int> saveNUM;
    int n,ans,digit,power;
    cout<<"Enter a narcissistic number: ";
    cin>>n;
    int input = n;
    seprate(input,digit,arr);
    PrintVEC(arr);
    power = arr.size();
    // cout<<endl;
    // cout<<"Size of vector is: "<<power;
    // cout<<endl;
    Power_fun(power, saveNUM, arr);
    PrintVEC1(saveNUM);
    sumVec(sum, saveNUM);
    check(sum, n);
    return 0;
}