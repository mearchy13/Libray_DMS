#ifndef PATRON_H
#include <iostream>
#include <string>

using namespace std;

class Patron {
public:
	Patron();
	Patron(string name, int ID, float fine, int borrowed);
	string getName();
	string setName();
	int getID();
	int setID();
	float getBalance();
	float setBalance();
	int getBorrowedbook();
	int setBorrowedbook();
private:
	string patronName;
	int patronID;
	float fineBalance;
	int booksBorrowed;
};

#endif
