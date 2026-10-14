#ifndef FINE_H
#define FINE_H
#include <string>
using namespace std;
class Fine { string memberId,bookId; double amount; bool paid; public: Fine(string m="",string b="",double a=0,bool p=false); string getMemberId()const; string getBookId()const; double getAmount()const; bool isPaid()const; void setPaid(bool); void display()const; };
#endif
