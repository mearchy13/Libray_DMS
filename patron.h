#ifndef PATRON_H
#include <iostream>
#include <string>

using namespace std;

class Patron {
public:
	Patron();
	Patron(string name, int pID, float fine, int borrowed);
	string getName();
	void setName(string name);
	int getID();
	void setID(int pID);
	float getBalance();
	void setBalance(float fine);
	int getBorrowedbook();
	void setBorrowedbook(int borrowed);
	Patron* getnext();
	void setnext(Patron* p);

private:
	Patron* next;
	string patronName;
	int patronID;
	float fineBalance;
	int numBooksBorrowed;
};

#endif
