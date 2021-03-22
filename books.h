#ifndef BOOKS_H
#define BOOKS_H

#include <vector>
#include "book.h"

class Books {
public:
	Books();
	int getcount();
	void incount();
	void decount();
	void addBook();
	void editBook();
	void delBook(int);
	Book *findBook(int);
	void cleanup();
	void printBook();
	void loadBook();
	void storeBook();
private:
	int bookCount;
	std::vector <Book*> bookList;
};

#endif
