#include <iostream>
#include <typeinfo>
using namespace std;

int main() 
{
  int myInt = 9.99;  // Automatic conversion: double to int (truncates)
  cout << myInt;     // 9
  cout << typeid(myInt).name();
  double myDouble = 9;
    cout << myDouble<< endl;
    cout<<typeid(myDouble).name();
  return 0;
}
