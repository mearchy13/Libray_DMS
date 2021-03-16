#ifndef PATRON_H
#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	Book();
	Book(string author, string title, int ISBN, int libraryID, float cost, string bookStatus);
	string getAuthor();
	string setAuthor();
	string setTitle();
	string getTitle();
	int getISBN();
	int setISBN();
	int getlibraryID();
	int setLibraryID();
	float setCost();
	float getCost();
	string setBookStatus();
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

