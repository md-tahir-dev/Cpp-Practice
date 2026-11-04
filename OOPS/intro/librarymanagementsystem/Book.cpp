#include "Book.h"

#include <iostream>

Book::Book()
    : title(), author(), bookID(0), issued(false)
{
}

Book::Book(const std::string& title, const std::string& author, int bookID)
    : title(title), author(author), bookID(bookID), issued(false)
{
}

const std::string& Book::getTitle() const
{
    return title;
}

const std::string& Book::getAuthor() const
{
    return author;
}

int Book::getBookID() const
{
    return bookID;
}

bool Book::isIssued() const
{
    return issued;
}

bool Book::issue()
{
    if (issued)
    {
        return false;
    }

    issued = true;
    return true;
}

bool Book::returnBook()
{
    if (!issued)
    {
        return false;
    }

    issued = false;
    return true;
}

void Book::display() const
{
    std::cout << "ID: " << bookID
              << ", Title: " << title
              << ", Author: " << author
              << ", Status: " << (issued ? "Issued" : "Available")
              << '\n';
}
