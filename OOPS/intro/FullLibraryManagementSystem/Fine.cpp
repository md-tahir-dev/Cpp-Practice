#include "Fine.h"
#include <iostream>
using namespace std;
Fine::Fine(string m,string b,double a,bool p):memberId(m),bookId(b),amount(a<0?0:a),paid(p){} string Fine::getMemberId()const{return memberId;} string Fine::getBookId()const{return bookId;} double Fine::getAmount()const{return amount;} bool Fine::isPaid()const{return paid;} void Fine::setPaid(bool p){paid=p;} void Fine::display()const{cout<<"Member "<<memberId<<" | Book "<<bookId<<" | Fine "<<amount<<" | "<<(paid?"Paid":"Unpaid")<<'\n';}
