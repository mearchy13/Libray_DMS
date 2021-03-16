#include "book.h"

Book::Book() {
	string bookAuthor = " "; string bookTitle = " "; int bookISBN = 0; int bookLID = 0; float bookCost = 0.00; string currBookStatus = " ";
}
Book::Book(string author, string title, int ISBN, int libraryID, float cost, string bookStatus) {
	author = bookAuthor; title = bookTitle; ISBN = bookISBN; libraryID = bookLID; cost = bookCost; bookStatus = currBookStatus;
}
