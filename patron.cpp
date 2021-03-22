#include "patron.h"

Patron::Patron() {
	next=NULL; patronName=" "; patronID=0; fineBalance=0; numBooksBorrowed=0;
}
Patron::Patron(string name, int pID, float fine, int borrowed) {
	patronName = name; patronID = pID; fineBalance = fine; numBooksBorrowed = borrowed;
}
string Patron::getName() { return patronName; }
void Patron::setName(string name) { patronName = name; }
int Patron::getID() { return patronID; }
void Patron::setID(int pID) { patronID = pID; }
float Patron::getBalance() { return fineBalance; }
void Patron::setBalance(float fine) { fineBalance = fine; }
int Patron::getBorrowedbook() { return numBooksBorrowed; }
void Patron::setBorrowedbook(int borrowed) { numBooksBorrowed = borrowed; }
Patron* Patron::getnext() { return next; }
void Patron::setnext(Patron* p) { next = p; }