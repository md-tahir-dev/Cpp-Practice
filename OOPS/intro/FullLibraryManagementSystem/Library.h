#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Member.h"
#include "IssueRecord.h"
#include "Fine.h"
class Library {
    Book books[100]; Member members[100]; IssueRecord records[500]; Fine fines[500];
    int nb,nm,nr,nf;
    void load(); void saveBooks()const; void saveMembers()const; void saveRecords()const; void saveFines()const;
    int bookIndex(const string&)const; int memberIndex(const string&)const;
public:
    Library();
    void addBook(string,string,string); void showBooks()const;
    void addMember(string,string,string); void showMembers()const;
    void issue(string,string,string); void giveBack(string,string,double);
    void showRecords()const; void showFines()const; void payFine(string,string);
};
#endif
