#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 2;
    double sum = static_cast<double>(a)/(b);  // sstatic_cast<> for ordinary numeric conversions. It documents your intent and is safer than a C-style cast.
    cout<<sum;
    return 0;
}