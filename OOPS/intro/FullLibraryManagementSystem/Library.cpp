#include "Library.h"
#include <fstream>
#include <iostream>
using namespace std;
Library::Library():nb(0),nm(0),nr(0),nf(0){load();}
int Library::bookIndex(const string& x)const{for(int i=0;i<nb;i++)if(books[i].getId()==x)return i;return -1;}
int Library::memberIndex(const string& x)const{for(int i=0;i<nm;i++)if(members[i].getId()==x)return i;return -1;}
void Library::load(){
 ifstream f("books.txt"); string a,b,c,d;
 while(nb<100&&getline(f,a,'|')&&getline(f,b,'|')&&getline(f,c,'|')&&getline(f,d))books[nb++]=Book(a,b,c,d=="1");
 ifstream m("members.txt"); while(nm<100&&getline(m,a,'|')&&getline(m,b,'|')&&getline(m,c))members[nm++]=Member(a,b,c);
 ifstream r("issue_records.txt"); while(nr<500&&getline(r,a,'|')&&getline(r,b,'|')&&getline(r,c,'|')&&getline(r,d))records[nr++]=IssueRecord(a,b,c,d=="1");
 ifstream q("fines.txt"); string amount,paid; while(nf<500&&getline(q,a,'|')&&getline(q,b,'|')&&getline(q,amount,'|')&&getline(q,paid)){try{fines[nf++]=Fine(a,b,stod(amount),paid=="1");}catch(...){}}
}
void Library::saveBooks()const{ofstream f("books.txt");for(int i=0;i<nb;i++)f<<books[i].getId()<<'|'<<books[i].getTitle()<<'|'<<books[i].getAuthor()<<'|'<<(books[i].isIssued()?1:0)<<'\n';}
void Library::saveMembers()const{ofstream f("members.txt");for(int i=0;i<nm;i++)f<<members[i].getId()<<'|'<<members[i].getName()<<'|'<<members[i].getType()<<'\n';}
void Library::saveRecords()const{ofstream f("issue_records.txt");for(int i=0;i<nr;i++)f<<records[i].getBookId()<<'|'<<records[i].getMemberId()<<'|'<<records[i].getDate()<<'|'<<(records[i].isReturned()?1:0)<<'\n';}
void Library::saveFines()const{ofstream f("fines.txt");for(int i=0;i<nf;i++)f<<fines[i].getMemberId()<<'|'<<fines[i].getBookId()<<'|'<<fines[i].getAmount()<<'|'<<(fines[i].isPaid()?1:0)<<'\n';}
void Library::addBook(string id,string title,string author){if(id.empty()||title.empty()||author.empty()){cout<<"Fields cannot be empty.\n";return;}if(bookIndex(id)>=0||nb>=100){cout<<"Duplicate ID or book storage full.\n";return;}books[nb++]=Book(id,title,author);saveBooks();cout<<"Book added.\n";}
void Library::showBooks()const{if(!nb)cout<<"No books.\n";for(int i=0;i<nb;i++)books[i].display();}
void Library::addMember(string id,string name,string type){if(id.empty()||name.empty()){cout<<"ID/name required.\n";return;}if(memberIndex(id)>=0||nm>=100){cout<<"Duplicate ID or member storage full.\n";return;}members[nm++]=Member(id,name,type);saveMembers();cout<<"Member registered.\n";}
void Library::showMembers()const{if(!nm)cout<<"No members.\n";for(int i=0;i<nm;i++)cout<<members[i].getId()<<" | "<<members[i].getName()<<" | "<<members[i].getType()<<'\n';}
void Library::issue(string bid,string mid,string date){int b=bookIndex(bid);if(b<0||memberIndex(mid)<0){cout<<"Book or member not found.\n";return;}if(books[b].isIssued()||nr>=500){cout<<"Book already issued or record storage full.\n";return;}books[b].setIssued(true);records[nr++]=IssueRecord(bid,mid,date);saveBooks();saveRecords();cout<<"Book issued.\n";}
void Library::giveBack(string bid,string mid,double amount){int b=bookIndex(bid);if(b<0||!books[b].isIssued()){cout<<"Book not found or not issued.\n";return;}int r=-1;for(int i=nr-1;i>=0;i--)if(records[i].getBookId()==bid&&records[i].getMemberId()==mid&&!records[i].isReturned()){r=i;break;}if(r<0){cout<<"No active issue record for this member.\n";return;}records[r].setReturned(true);books[b].setIssued(false);if(amount>0&&nf<500)fines[nf++]=Fine(mid,bid,amount);saveBooks();saveRecords();saveFines();cout<<"Book returned.\n";}
void Library::showRecords()const{if(!nr)cout<<"No issue records.\n";for(int i=0;i<nr;i++)records[i].display();}
void Library::showFines()const{if(!nf)cout<<"No fines.\n";for(int i=0;i<nf;i++)fines[i].display();}
void Library::payFine(string mid,string bid){for(int i=0;i<nf;i++)if(fines[i].getMemberId()==mid&&fines[i].getBookId()==bid&&!fines[i].isPaid()){fines[i].setPaid(true);saveFines();cout<<"Fine paid.\n";return;}cout<<"Unpaid fine not found.\n";}
