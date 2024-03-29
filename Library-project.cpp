#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Book {
private:
    string title;
    string author;
    int quantity;

public:
    Book(string title, string author, int quantity) : title(title), author(author), quantity(quantity) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    string toString() const {
        stringstream ss;
        ss << title << "," << author << "," << quantity;
        return ss.str();
    }
};

class Member {
private:
    string name;
    int memberId;

public:
    Member(string name, int memberId) : name(name), memberId(memberId) {}

    string getName() const {
        return name;
    }

    int getMemberId() const {
        return memberId;
    }

    string toString() const {
        stringstream ss;
        ss << name << "," << memberId;
        return ss.str();
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const Book& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Quantity: " << book.getQuantity() << endl;
        }
    }

    void deleteBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
    }

    void updateBook(const string& title, int newQuantity) {
        for (Book& book : books) {
            if (book.getTitle() == title) {
                book.setQuantity(newQuantity);
                break;
            }
        }
    }

    void addMember(const Member& member) {
        members.push_back(member);
    }

    void displayMembers() const {
        for (const Member& member : members) {
            cout << "Name: " << member.getName() << ", Member ID: " << member.getMemberId() << endl;
        }
    }

    void saveDataToFile(const string& booksFilename, const string& membersFilename) const {
        ofstream booksFile(booksFilename);
        ofstream membersFile(membersFilename);
        if (booksFile.is_open() && membersFile.is_open()) {
            for (const Book& book : books) {
                booksFile << book.toString() << endl;
            }
            for (const Member& member : members) {
                membersFile << member.toString() << endl;
            }
            booksFile.close();
            membersFile.close();
        } else {
            cout << "Unable to open files for saving." << endl;
        }
    }

    void loadDataFromFile(const string& booksFilename, const string& membersFilename) {
        ifstream booksFile(booksFilename);
        ifstream membersFile(membersFilename);
        if (booksFile.is_open() && membersFile.is_open()) {
            string line;
            // Load books
            while (getline(booksFile, line)) {
                stringstream ss(line);
                string title, author;
                int quantity;
                getline(ss, title, ',');
                getline(ss, author, ',');
                ss >> quantity;
                addBook(Book(title, author, quantity));
            }
            // Load members
            while (getline(membersFile, line)) {
                stringstream ss(line);
                string name;
                int memberId;
                getline(ss, name, ',');
                ss >> memberId;
                addMember(Member(name, memberId));
            }
            booksFile.close();
            membersFile.close();
        } else {
            cout << "Unable to open files for loading." << endl;
        }
    }
};

int main() {
    Library library;

    // Load existing data from files if available
    library.loadDataFromFile("./db/books.csv", "./db/members.csv");

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Update Book\n";
        cout << "5. Add Member\n";
        cout << "6. Display Members\n";
        cout << "7. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int quantity;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Quantity: ";
                cin >> quantity;
                library.addBook(Book(title, author, quantity));
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                string title;
                cout << "Enter Title to delete: ";
                cin.ignore();
                getline(cin, title);
                library.deleteBook(title);
                break;
            }
            case 4: {
                string title;
                int newQuantity;
                cout << "Enter Title to update: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter New Quantity: ";
                cin >> newQuantity;
                library.updateBook(title, newQuantity);
                break;
            }
            case 5: {
                string name;
                int memberId;
                cout << "Enter Member Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Member ID: ";
                cin >> memberId;
                library.addMember(Member(name, memberId));
                break;
            }
            case 6:
                library.displayMembers();
                break;
            case 7:
                library.saveDataToFile("./db/books.csv", "./db/members.csv");
                cout << "Library data saved successfully. Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
