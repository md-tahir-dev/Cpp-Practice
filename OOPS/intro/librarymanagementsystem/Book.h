#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    int bookID;
    bool issued;

public:
    Book();
    Book(const std::string& title, const std::string& author, int bookID);

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getBookID() const;
    bool isIssued() const;

    bool issue();
    bool returnBook();
    void display() const;
};

#endif
