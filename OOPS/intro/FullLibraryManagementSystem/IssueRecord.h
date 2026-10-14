#ifndef ISSUE_RECORD_H
#define ISSUE_RECORD_H
#include <string>
using namespace std;
class IssueRecord { string bookId,memberId,date; bool returned; public: IssueRecord(string b="",string m="",string d="",bool r=false); string getBookId()const; string getMemberId()const; string getDate()const; bool isReturned()const; void setReturned(bool); void display()const; };
#endif
