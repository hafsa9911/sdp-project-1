# Library Management System

The Library Management System is a command-line application built in C++ to manage a library's book inventory and member records. This program allows users to perform various tasks such as adding, retrieving, updating, and deleting books, as well as adding new members and issuing books to them.

## Features

1. *Add Books*: Users can add new books to the library inventory, providing details such as title, author, and quantity.
2. *Display Books*: View a list of all available books in the library along with their details.
3. *Delete Book*: Remove a book from the library inventory by providing its title.
4. *Update Book*: Modify the quantity of a book in the inventory.
5. *Add Member*: Add new members to the library, including their name and a unique member ID.
6. *Display Members*: View a list of all library members along with their details.
7. *Save Data*: The data for books and members is stored in separate CSV files for persistence.
8. *Run via CLI*: The program can be run directly from the command line.

## How to Run

1. Clone the repository to your local machine:

bash
git clone https://github.com/hafsa9911/sdp-project-1.git


2. Navigate to the project directory:

bash
cd library-management-system


3. Compile the app.cpp file:

bash
g++ -std=c++11 app.cpp -o library_management_system


4. Run the compiled executable:

bash
./library_management_system


Follow the on-screen instructions to use the Library Management System.