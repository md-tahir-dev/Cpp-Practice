#include "Library.h"
#include <iostream>
#include <limits>
using namespace std;
int main()
{
    Library lib;
    int ch;
    do
    {
        cout << "\n=== LIBRARY MANAGEMENT ===\n1 Add book\n2 Show books\n3 Register member\n4 Show members\n5 Issue book\n6 Return book\n7 Issue records\n8 Show fines\n9 Pay fine\n0 Exit\nChoice: ";
        if (!(cin >> ch))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string id, title, author, name, type, bid, mid, date;
        double fine;
        switch (ch)
        {
        case 1:
            cout << "Book ID: ";
            getline(cin, id);
            cout << "Title: ";
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;
        case 2:
            lib.showBooks();
            break;
        case 3:
            cout << "Member ID: ";
            getline(cin, id);
            cout << "Name: ";
            getline(cin, name);
            cout << "Type (Student/Teacher/General): ";
            getline(cin, type);
            lib.addMember(id, name, type);
            break;
        case 4:
            lib.showMembers();
            break;
        case 5:
            cout << "Book ID: ";
            getline(cin, bid);
            cout << "Member ID: ";
            getline(cin, mid);
            cout << "Issue date (YYYY-MM-DD): ";
            getline(cin, date);
            lib.issue(bid, mid, date);
            break;
        case 6:
            cout << "Book ID: ";
            getline(cin, bid);
            cout << "Member ID: ";
            getline(cin, mid);
            cout << "Fine amount (0 if none): ";
            if (!(cin >> fine))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (fine < 0)
            {
                cout << "Fine cannot be negative.\n";
                break;
            }
            lib.giveBack(bid, mid, fine);
            break;
        case 7:
            lib.showRecords();
            break;
        case 8:
            lib.showFines();
            break;
        case 9:
            cout << "Member ID: ";
            getline(cin, mid);
            cout << "Book ID: ";
            getline(cin, bid);
            lib.payFine(mid, bid);
            break;
        case 0:
            cout << "Goodbye.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (ch != 0);
}
