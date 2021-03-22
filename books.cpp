#include "books.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

Books::Books() {bookCount = 0;}

int Books::getcount() { return bookCount; }
void Books::incount() { bookCount++; }
void Books::decount() { bookCount--; }
/*Add Book
Prompt user for Author
Prompt user for Title
Prompt user for ISBN number
Prompt user for Library ID number
Prompt user for cost
Create books object
Populate book object
Add object to collection*/

void Books::addBook() {
	string author, title, bookStatus; int ISBN, libraryID; float cost;
	Book *temp;

	cout << "Author: "; cin >> author;
	cout << "\nTitle: "; cin >> title;
	cout << "\nISBN: "; cin >> ISBN; 
	cout << "\nLibrary ID number: "; cin >> libraryID;
	cout << "\nCost: "; cin >> cost;
	cout << "\nCurrent Status"; cin >> bookStatus;
	cout << endl;

	temp = new Book( author, title, ISBN, libraryID, cost, bookStatus);
	bookList.push_back(temp);
	incount();
}
/*Edit Book

If add book in loan
Current status = out
If delete book in loan
Current status = in
If edit book in loan
Current status = no change / out*/

void Books::editBook() {
	char choice; int i;
	string author, title, bookStatus; int ISBN, libraryID; float cost;
	cout << "Enter Library ID of book to edit:"; cin >> libraryID; cout << endl;
	for ( i = 0; i < bookCount; i++) {
		if (bookList[i]->getLibraryID() == libraryID) {
		}
	}
		cout << "EDIT BOOK MENU\na - Edit Author\nb - Edit Title\nc - Edit ISBN number\nd - Edit Cost\ne - Edit Book Status\n0 - exit\n";
		cin >> choice; cin.ignore();
		while (choice != 0) {
			switch (choice) {
			case 'a':
				cout << "Change Author to: ";
				getline(cin, author);
				bookList.at(i)->setAuthor(author);
				break;
			case 'b':
				cout << "Change title to: ";
				getline(cin, title);
				bookList.at(i)->setTitle(title);
				break;
			case 'c':
				cout << "Change ISBN to: ";
				cin >> ISBN; cin.ignore();
				bookList.at(i)->setISBN(ISBN);
				break;
			case 'd':
				cout << "Change cost: ";
				cin >> cost; cin.ignore();
				bookList.at(i)->setCost(cost);
				break;
			case 'e':
				cout << "Change Book Status: ";
				cin >> bookStatus; cin.ignore();
				bookList.at(i)->setBookStatus(bookStatus);
				break;
			}
		}
}
/*Delete Book

Prompt user for Library ID number
Delete matching data*/

void Books::delBook(int libraryID) {
	for (auto it = bookList.begin(); it != bookList.end(); ++it) {
		if ((*it)->getLibraryID() == libraryID) {
			bookList.erase(it);
		}
	}
}
/*Search book by Library ID

Prompt user for Library ID
If Library ID matched data in book
Return book*/

Book* Books::findBook(int libraryID) {
	for (int i = 0; i < bookCount; i++)
	{
		if (bookList[i]->getLibraryID() == libraryID) return bookList[i];

	}

	return NULL;
}
void Books::cleanup() {
	for (auto it = bookList.begin(); it != bookList.end(); ++it)
	{

		delete* it;
	}
	bookList.clear();
}
/*Print book by Title

Prompt user for Title
Find book by title(return library ID)
Search all book(by Library ID)
If Library ID matches book
Print book detail

Print book by ISBN number

Prompt user for ISBN number
Find book by ISBN number(return Library ID)
Search all book(by Library ID)
If Library ID matches book
Print book detail

Print book by Library ID

Prompt user for library ID
Search all book
If Library ID matches book
Print book detail*/

void Books::printBook() {
	Book* temp;
	for (auto it = bookList.begin(); it != bookList.end(); ++it)
	{
		temp = *it;
		cout << "\nAuthor: " << temp->getAuthor() << "\nTitle:" << temp->getTitle() << "\nISBN Number: " << temp->getISBN() << "\nLibrary ID:  " << temp->getLibraryID() << "Cost: " << temp->getBookStatus() << "\nCurrent Staus: " << temp->getBookStatus() << endl;

	}
}
void Books::loadBook() {
	ifstream in;
	string author, title, bookStatus; int ISBN, libraryID; float cost;
	in.open("books.dat");
	in >> bookCount;
	in.ignore();
	for (int i = 0; i < bookCount; i++) {
		in >> author >> title >> ISBN >> libraryID >> cost >> bookStatus;
		bookList.push_back(new Book(author, title, ISBN, libraryID, cost, bookStatus));
	}
	in.close();
}
void Books::storeBook() {
	Book* temp;
	ofstream out;
	out.open("books.dat");
	out << bookCount << endl;
	for (auto it = bookList.begin(); it != bookList.end(); ++it) {
		temp = *it;
		out << temp->getAuthor() << " " << temp->getTitle() << " " << temp->getISBN() << " " << temp->getLibraryID() << " " << temp->getBookStatus() << " " << temp->getBookStatus() << endl;
	}
	out.close();
}