#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    bool isIssued;

public:
    Book(string title = "", string author = "", bool isIssued = false);

    void issueBook();
    void returnBook();
    void displayBook() const;

    string getTitle() const;
    string getAuthor() const;
    bool getIsIssued() const;
};

class Library
{
private:
    Book books[5];
    int count;

    void loadBooks();
    void saveBooks() const;

public:
    Library();

    void addBook(string title, string author);
    void displayBooks() const;
    void issueBook(string title);
    void returnBook(string title);
};

#endif