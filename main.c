#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Book
{
    /* data */
    int id;
    char title[100];
    char author[100];
    int publicationYear;
    struct Book *next;
} Book;

Book* head = NULL;

void addBook(int id, char* title, char* author, int year){

    Book* newBook = (Book*) malloc(sizeof(Book)); //Allocating memory for a new book
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publicationYear = year;
    newBook->next = NULL;

    if(head == NULL){
        head = newBook;
    }
    else{
        Book* temp =head;

        while(temp->next != NULL){
            temp =  temp->next;
        }
        temp->next = newBook;
    }
    printf("Book has been added!\n");
}

void removeBook(int id){
    Book* temp = head;
    Book* target = NULL;

    // Case 1: If the book to be removed is the head

    if(temp!=NULL && temp->id == id){
        head = temp->next;
        free(temp);
        printf("Book removed successfully!\n");
        return;
    }

    // Case 2: Search for the book in the list
    while(temp!=NULL && temp->id != id){
        target = temp;
        temp = temp->next;
    }

    // Case 3: Book is not in the library
    if(temp == NULL){
        printf("Your book with the ID %d was not found\n", id);
        return;
    }

    // Case 4: Book found, unlink it from the list
    target->next = temp->next;
    free(temp);
    printf("Book removed successfully!\n");
}

// Function: List/Print ALL books

void listBooks(){
    Book* current = head;
    if(current ==NULL){
        printf("There are no books in the library!\n");
        return;
    }

    while(current !=NULL){
        printf("[ID: %d, Title: %s, Author: %s, Year: %d]\n\n", current->id, current->title, current->author, current->publicationYear);

        current = current->next;
    }
}

// Function: Search for a Book
Book* searchBook(char* title){
    Book* current = head;

    while(current !=NULL){
        if(strcmp(current->title, title) == 0){
            return current;
        }

        current = current->next;
    }
    return NULL; // BOOK not found
}

int main(){
    printf("Welcome to my Library System!\n");
    addBook(1, "C Programming", "C Author", 2021);
    addBook(2, "Python Programming", "Python's Author", 2022);
    addBook(3, "Docker", "Docker's Author", 2023);

    printf("Listing all books:\n");
    listBooks();

    Book* book = searchBook("Docker");

    if (book != NULL) {
        printf("Book found: ID: %d, Title: %s, Author: %s, Year: %d\n", book->id, book->title, book->author, book->publicationYear);
    } else {
        printf("Book not found.\n");
    }

    printf("\nRemoving book with ID 2:\n");
    removeBook(2);

    printf("\nListing all books after removal:\n");
    listBooks();

    

    return 0;

}