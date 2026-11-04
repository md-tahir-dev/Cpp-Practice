#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

#include <string>

class Library
{
private:
    Book books[5];
    int bookCount;

public:
    Library();

    bool addBook(const Book& book);
    Book* searchByTitle(const std::string& title);
    const Book* searchByTitle(const std::string& title) const;
    int countAvailableBooks() const;
    int countIssuedBooks() const;
    void displayBooksByAuthor(const std::string& author) const;
};

#endif
