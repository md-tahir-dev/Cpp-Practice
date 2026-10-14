#include "IssueRecord.h"
#include <iostream>
using namespace std;
IssueRecord::IssueRecord(string b,string m,string d,bool r):bookId(b),memberId(m),date(d),returned(r){} string IssueRecord::getBookId()const{return bookId;} string IssueRecord::getMemberId()const{return memberId;} string IssueRecord::getDate()const{return date;} bool IssueRecord::isReturned()const{return returned;} void IssueRecord::setReturned(bool r){returned=r;} void IssueRecord::display()const{cout<<"Book "<<bookId<<" | Member "<<memberId<<" | Date "<<date<<" | "<<(returned?"Returned":"Borrowed")<<'\n';}
