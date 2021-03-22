#include "book.h"

Book::Book() {
	bookAuthor = " "; bookTitle = " ";  bookISBN = 0;  bookLID = 0;  bookCost = 0.00; currBookStatus = " ";
}
Book::Book(string author, string title, int ISBN, int libraryID, float cost, string bookStatus) {
	 bookAuthor= author; bookTitle= title; bookISBN = ISBN;   bookLID = libraryID; bookCost = cost;  currBookStatus = bookStatus ;
}
string Book::getAuthor() { return bookAuthor; }
void Book::setAuthor(string author) { bookAuthor = author; }
void Book::setTitle(string title) { bookTitle = title; }
string Book::getTitle() { return bookTitle; }
int Book::getISBN() { return bookISBN; }
void Book::setISBN(int ISBN) { bookISBN = ISBN; }
int Book::getLibraryID() { return bookLID; }
void Book::setLibraryID(int libraryID) { bookLID = libraryID; }
void Book::setCost(float cost) { bookCost = cost; }
float Book::getCost() { return bookCost; }
void Book::setBookStatus(string bookStatus) { currBookStatus = bookStatus; }
string Book::getBookStatus() { return currBookStatus; }