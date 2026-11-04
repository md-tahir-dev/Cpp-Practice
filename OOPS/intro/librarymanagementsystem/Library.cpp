#include "Library.h"

#include <iostream>

using namespace std;

Library::Library()
    : books(), bookCount(0)
{
}

bool Library::addBook(const Book& book)
{
    if (bookCount >= 5)
    {
        return false;
    }

    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].getBookID() == book.getBookID())
        {
            cout<<"You entered invalid book id."<<endl;
            return false;
        }
    }

    books[bookCount] = book;
    ++bookCount;
    return true;
}

Book* Library::searchByTitle(const std::string& title)
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].getTitle() == title)
        {
            return &books[i];
        }
    }

    return 0;
}

const Book* Library::searchByTitle(const std::string& title) const
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].getTitle() == title)
        {
            return &books[i];
        }
    }

    return 0;
}

int Library::countAvailableBooks() const
{
    int availableCount = 0;
    for (int i = 0; i < bookCount; ++i)
    {
        if (!books[i].isIssued())
        {
            ++availableCount;
        }
    }

    return availableCount;
}

int Library::countIssuedBooks() const
{
    int issuedCount = 0;
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].isIssued())
        {
            ++issuedCount;
        }
    }

    return issuedCount;
}

void Library::displayBooksByAuthor(const std::string& author) const
{
    bool found = false;
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].getAuthor() == author)
        {
            books[i].display();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No books found for author: " << author << '\n';
    }
}
