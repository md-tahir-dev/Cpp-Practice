#include<iostream>
using namespace std;

bool isEven(int num)
{
    if(num % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    bool result = isEven(num);

    cout << result;

    return 0;
}