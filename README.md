# Library Management System

This is a simple Library Management System implemented in C. It allows users to manage a collection of books by adding, removing, listing, and searching for books in the library.

## Features

- **Add a Book**: Add a new book to the library with a unique ID, title, author, and publication year.
- **Remove a Book**: Remove an existing book from the library using its unique ID.
- **List All Books**: Display all books currently available in the library.
- **Search for a Book**: Search for a book by its title.

## Code Structure

- **Data Structure**: The library uses a linked list to store books. Each book is represented by a `Book` struct containing its ID, title, author, publication year, and a pointer to the next book in the list.

## Functions

- `addBook(int id, char* title, char* author, int year)`: Adds a new book to the library.
- `removeBook(int id)`: Removes a book from the library by its ID.
- `listBooks()`: Lists all books currently in the library.
- `searchBook(char* title)`: Searches for a book by its title and returns a pointer to the book if found.

## Getting Started

### Prerequisites

- A C compiler such as `gcc`.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o library_management_system main.c
```

### Running the Program
After compiling, you can run the program using:
```bash
./library_management_system
```
