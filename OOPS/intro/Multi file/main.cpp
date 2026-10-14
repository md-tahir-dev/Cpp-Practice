#include "header.h"
#include "header.h"

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