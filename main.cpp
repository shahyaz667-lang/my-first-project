#include <iostream>
#include <string>
using namespace std;

// Library Management System using a Singly Linked List

struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

class Library {
private:
    Book* head;

public:
    Library() {
        head = nullptr;
    }

    // Add a new book at the end of the linked list
    void addBook(int id, string title, string author) {
        Book* newBook = new Book;
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }

        cout << "Book added successfully.\n";
    }

    // Display all books
    void displayBooks() {
        if (head == nullptr) {
            cout << "No books are available.\n";
            return;
        }

        Book* temp = head;
        cout << "\n----- Library Books -----\n";

        while (temp != nullptr) {
            cout << "Book ID: " << temp->id << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }

    // Search a book by ID
    void searchBook(int id) {
        Book* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "\nBook found!\n";
                cout << "Book ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Author: " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.\n";
    }

    // Delete a book by ID
    void deleteBook(int id) {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book deleted successfully.\n";
            return;
        }

        Book* current = head;

        while (current->next != nullptr && current->next->id != id) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Book not found.\n";
            return;
        }

        Book* temp = current->next;
        current->next = current->next->next;
        delete temp;

        cout << "Book deleted successfully.\n";
    }

    // Destructor to release dynamically allocated memory
    ~Library() {
        Book* current = head;

        while (current != nullptr) {
            Book* nextBook = current->next;
            delete current;
            current = nextBook;
        }
    }
};

int main() {
    Library library;
    int choice;

    // Sample data
    library.addBook(101, "Introduction to Algorithms", "Thomas H. Cormen");
    library.addBook(102, "Data Structures and Algorithms", "Mark Allen Weiss");

    do {
        cout << "\n========== Library Management System ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string title, author;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            library.addBook(id, title, author);
            break;
        }

        case 2:
            library.displayBooks();
            break;

        case 3: {
            int id;
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.searchBook(id);
            break;
        }

        case 4: {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            library.deleteBook(id);
            break;
        }

        case 5:
            cout << "Thank you for using the Library Management System.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
