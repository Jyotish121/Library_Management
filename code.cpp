#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;

    Book(int id, string title, string author) : id(id), title(title), author(author) {}
};

class LibraryManagementSystem {
private:
    vector<Book> books;
    int generateId() {
        return books.size() + 1;
    }

public:
    void addBook(string title, string author) {
        int id = generateId();
        books.push_back(Book(id, title, author));
        cout << "Book added successfully with ID: " << id << endl;
    }

    void removeBook(int id) {
        auto it = find_if(books.begin(), books.end(), [id](Book &book) {
            return book.id == id;
        });
        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully!" << endl;
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void searchBook(string searchString) {
        bool found = false;
        for (const auto &book : books) {
            if (book.title.find(searchString) != string::npos || book.author.find(searchString) != string::npos) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the search criteria." << endl;
        }
    }

    void sortBooksByTitle() {
        sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.title < b.title;
        });
        cout << "Books sorted by title successfully!" << endl;
    }

    void sortBooksByAuthor() {
        sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.author < b.author;
        });
        cout << "Books sorted by author successfully!" << endl;
    }

    void sortBooksById() {
        sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.id < b.id;
        });
        cout << "Books sorted by ID successfully!" << endl;
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
        } else {
            for (const auto &book : books) {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
            }
        }
    }
};

int main() {
    LibraryManagementSystem lms;
    int choice;
    string title, author;
    int id;

    do {
        cout << "--- Library Management System ---" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Sort Books by Title" << endl;
        cout << "5. Sort Books by Author" << endl;
        cout << "6. Sort Books by ID" << endl;
        cout << "7. Display All Books" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            lms.addBook(title, author);
            break;
        case 2:
            cout << "Enter book ID to remove: ";
            cin >> id;
            lms.removeBook(id);
            break;
        case 3:
            cout << "Enter title or author to search: ";
            cin.ignore();
            getline(cin, title);
            lms.searchBook(title);
            break;
        case 4:
            lms.sortBooksByTitle();
            break;
        case 5:
            lms.sortBooksByAuthor();
            break;
        case 6:
            lms.sortBooksById();
            break;
        case 7:
            lms.displayAllBooks();
            break;
        case 8:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
