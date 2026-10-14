#include "header.h"
#include <fstream>

Book::Book(string title, string author, bool isIssued)
{
    this->title = title;
    this->author = author;
    this->isIssued = isIssued;
}

void Book::issueBook()
{
    if (!isIssued)
    {
        isIssued = true;
        cout << "Book \"" << title << "\" issued successfully." << endl;
    }
    else
    {
        cout << "Book \"" << title << "\" is already issued." << endl;
    }
}

void Book::returnBook()
{
    if (isIssued)
    {
        isIssued = false;
        cout << "Book \"" << title << "\" returned successfully." << endl;
    }
    else
    {
        cout << "Book \"" << title << "\" was not issued." << endl;
    }
}

void Book::displayBook() const
{
    cout << "Title: " << title
         << ", Author: " << author
         << ", Status: " << (isIssued ? "Issued" : "Available")
         << endl;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

bool Book::getIsIssued() const
{
    return isIssued;
}

Library::Library()
{
    count = 0;
    loadBooks();
}

void Library::loadBooks()
{
    ifstream inFile("books.txt");

    if (!inFile)
        return;

    string title, author, status;

    while (count < 5 &&
           getline(inFile, title, '|') &&
           getline(inFile, author, '|') &&
           getline(inFile, status))
    {
        books[count] = Book(title, author, status == "1");
        count++;
    }

    inFile.close();
}

void Library::saveBooks() const
{
    ofstream outFile("books.txt");

    if (!outFile)
    {
        cout << "Error: Could not save books.txt." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        outFile << books[i].getTitle() << '|'
                << books[i].getAuthor() << '|'
                << (books[i].getIsIssued() ? 1 : 0) << '\n';
    }

    outFile.close();
}

void Library::addBook(string title, string author)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            cout << "Book already exists in library." << endl;
            return;
        }
    }

    if (count >= 5)
    {
        cout << "Library is full." << endl;
        return;
    }

    books[count] = Book(title, author, false);
    count++;

    saveBooks();

    cout << "Book \"" << title << "\" added to library." << endl;
}

void Library::displayBooks() const
{
    cout << "\nLibrary Books:" << endl;

    if (count == 0)
    {
        cout << "No books found." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
        books[i].displayBook();
}

void Library::issueBook(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            bool wasIssued = books[i].getIsIssued();
            books[i].issueBook();

            if (!wasIssued)
                saveBooks();

            return;
        }
    }

    cout << "Book \"" << title << "\" not found in library." << endl;
}

void Library::returnBook(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            bool wasIssued = books[i].getIsIssued();
            books[i].returnBook();

            if (wasIssued)
                saveBooks();

            return;
        }
    }

    cout << "Book \"" << title << "\" not found in library." << endl;
}