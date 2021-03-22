#ifndef PATRONS_H
#define PATRONS_H
#include <vector>
#include "patron.h"

class Patrons {
public:
	Patrons();
	int getcount();
	void incount();
	void decount();
	void addPatron();
	void editPatron();
	void delPatron(int);
	Patron* findPatron(int);
	void printPatron();
	void payFine();
	void loadPatron();
	void storePatron();
private:
	int patronCount;
	vector<Patron*> patronList;
};
#endif
