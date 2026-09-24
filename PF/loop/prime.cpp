#include<iostream>      
using namespace std;   

int main()              
{
    int n, i;          
    bool isPrime = true; 
    cout << "Enter number: ";  
    cin >> n;                 
    if (n <= 1)             
        isPrime = false;       
    else                       
    {
        for (i = 2; i * i <= n; i++) 
        {
            if (n % i == 0)         
            {
                isPrime = false;     
                break;               
            }
        }
    }
    if (isPrime)              
        cout << "Prime";      
    else
        cout << "Not Prime";  
    return 0;                 
}