#include "Library.h"

#include <iostream>

int main()
{
    Library library;
    library.addBook(Book("The Hobbit", "J.R.R. Tolkien", 1));
    library.addBook(Book("The Fellowship of the Ring", "J.R.R. Tolkien", 2));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 2));

    if (!library.addBook(Book("Duplicate ID book", "Unknown Author", 1)))
    {
        std::cout << "A book with ID 1 already exists; duplicate was rejected.\n";
    }

    Book* book = library.searchByTitle("The Hobbit");
    if (book != 0)
    {
        std::cout << "Found book:\n";
        book->display();

        std::cout << "Issue successful: " << (book->issue() ? "yes" : "no") << '\n';
        std::cout << "Issue again successful: " << (book->issue() ? "yes" : "no") << '\n';
    }

    std::cout << "Available books: " << library.countAvailableBooks() << '\n';
    std::cout << "Issued books: " << library.countIssuedBooks() << '\n';

    if (book != 0)
    {
        std::cout << "Return successful: " << (book->returnBook() ? "yes" : "no") << '\n';
        std::cout << "Return again successful: " << (book->returnBook() ? "yes" : "no") << '\n';
    }

    std::cout << "\nBooks by J.R.R. Tolkien:\n";
    library.displayBooksByAuthor("J.R.R. Tolkien");
    std::cout << "Available books: " << library.countAvailableBooks() << '\n';
    std::cout << "Issued books: " << library.countIssuedBooks() << '\n';

    return 0;
}
