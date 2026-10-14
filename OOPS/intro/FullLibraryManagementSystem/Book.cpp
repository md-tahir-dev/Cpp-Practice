#include "Book.h"
#include <iostream>
using namespace std;
Book::Book(string i,string t,string a,bool x):id(i),title(t),author(a),issued(x){} string Book::getId()const{return id;} string Book::getTitle()const{return title;} string Book::getAuthor()const{return author;} bool Book::isIssued()const{return issued;} void Book::setIssued(bool x){issued=x;} void Book::display()const{cout<<"ID: "<<id<<" | "<<title<<" | "<<author<<" | "<<(issued?"Issued":"Available")<<'\n';}
