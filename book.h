#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	Book();
	Book(string author, string title, int ISBN, int libraryID, float cost, string bookStatus);
	string getAuthor();
	void setAuthor(string author);
	void setTitle(string title);
	string getTitle();
	int getISBN();
	void setISBN(int ISBN);
	int getLibraryID();
	void setLibraryID(int libraryID);
	void setCost(float cost);
	float getCost();
	void setBookStatus(string bookStatus);
	string getBookStatus();
private:
	string bookAuthor;
	string bookTitle;
	int bookISBN;
	int bookLID;
	float bookCost;
	string currBookStatus;
};

#endif

