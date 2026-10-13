// Create two classes:
// Book
// Library

// Book
// Private members:
// title
// author
// isIssued

// Constructor should initialize:
// - title
// - author
// - isIssued should initially be false
// Functions:
// issueBook()
// returnBook()
// displayBook()

// Rules:
// - A book can only be issued if it isn't already issued.
// - A book can only be returned if it is currently issued.
// Library
// Private member:
// Book books[5]

// The library can contain a maximum of 5 books.
// Functions:
// addBook()
// displayBooks()
// issueBook()
// returnBook()

// The library should manage the books.
// Main
// Create a library.
// Add at least 3 books.
// Then test:
// display all books
// issue a book
// try issuing the same book again
// return the book
// try returning it again
// display all books

// Restrictions
// For now:
// - Don't use inheritance.
// - Don't use polymorphism.
// - Don't use STL containers.
// - Use a normal array.
// - Book and Library must be separate classes.

#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string title;
    string author;
    bool isIssued = false;

public:
    Book(string title = "", string author = "")
    {
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
    void issueBook()
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

    void returnBook()
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
    void displayBook()
    {
        cout << "Book\"" << title << ", Author: " << author
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
    string getTitle()
    {
        return title;
    }
};

class Library
{
private:
    Book books[5];
    int count;

public:
    Library()
    {
        count = 0;
    }
    void addBook(string title, string author)
    {
        if (count < 5)
        {
            books[count] = Book(title, author);
            cout << "Book \"" << title << "\" added to library." << endl;
            count++;
        }
        else
        {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void displayBooks()
    {
        cout << "\nLibaray Books: " << endl;
        for (int i = 0; i < count; i++)
        {
            books[i].displayBook();
        }
        // cout << "Book \"" << title << "\" not found in library." << endl;
    }
    void issueBook(string title)
    {
        for (int i = 0; i < count; i++)
        {
            if (books[i].getTitle() == title)
            {
                books[i].issueBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in library." << endl;
    }

    void returnBook(string title)
    {
        for (int i = 0; i < count; i++)
        {
            if (books[i].getTitle() == title)
            {
                books[i].returnBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in library." << endl;
    }
};
int main()
{
    Library lib;

    lib.addBook("C++ Basics", "Bjarne Stroustrup");
    lib.addBook("Data Structures", "Mark Weiss");
    lib.addBook("Algorithms", "Thomas Cormen");
    lib.addBook("Clean Code", "Robert C. Martin");
    lib.addBook("Design Patterns", "Erich Gamma");

    lib.displayBooks();

    lib.issueBook("C++ Basics");

    lib.issueBook("C++ Basics");

    lib.returnBook("C++ Basics");

    lib.returnBook("C++ Basics");

    lib.displayBooks();

    return 0;
}