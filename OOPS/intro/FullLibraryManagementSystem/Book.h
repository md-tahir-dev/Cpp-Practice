#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class Book { string id,title,author; bool issued; public: Book(string id="",string title="",string author="",bool issued=false); string getId()const; string getTitle()const; string getAuthor()const; bool isIssued()const; void setIssued(bool); void display()const; };
#endif
