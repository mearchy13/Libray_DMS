#include "loans.h"
#include "books.h"
#include "patrons.h"
#include <ctime>
#include <fstream>
#include <iterator>


Loans::Loans() { loanCount = 0; }
void Loans::inLoan() { loanCount++; }
void Loans::deLoan() { loanCount--; }

int ID, bookID, patronID, dateAndtime; string loanStatus;
Book* currBook;
Patron* currPatron;
Loan* currLoan;
int numBookBorrow=0;
/*Check out book

Create Loan object
Find Patron with name / ID
If overdue books
No check out allowed
Else if total books out <= 6
No check out allowed
else if fines owned
No check out allowed
Else
Prompt user for book author / title / ISBN
Add book to patron list
Change book status to out*/

void Loans::bookOut(Books &bookList, Patrons &patronList) { 
	time_t now = time(0);
	Loan* temp;
	string status = " ";
	cout << "Enter Book ID: "; cin >> bookID;
	cout << "Enter Patron ID: "; cin >> patronID;
	cout << "Enter Loan ID: "; cin >>ID;
	currPatron = patronList.findPatron(patronID);
	numBookBorrow = currPatron->getBorrowedbook();
	if (numBookBorrow >= 6) {
		cout << "Limit reached!" << endl;
	}
	else {
		for (auto it = loanList.begin(); it != loanList.end(); ++it) {
			currLoan = *it;
			if (patronID == currLoan->getPatronID() && bookID == currLoan->getBookID()) {
				if (currLoan->getLoanStatus() == "Overdue") {
					cout << "Patron has overdue book(s)." << endl;
				}
				else {
					numBookBorrow++;
					currLoan->setDueDate(time(0) + (10 * 24 * 60 * 60));
					currBook->setBookStatus("Out");
					temp = new Loan(ID, bookID, patronID, dateAndtime, status);
					loanList.push_back(temp);
					loanCount++;
				}
			}
		}
	}
	
}

/*Check in book

Find Patron with name / ID
if current Dateand Time > due Dateand Time
Add fine
else
Remove book form patron list
change book status to in */

void Loans::bookIn(Books& bookList, Patrons& patronList) {
	time_t now = time(0);
	string status = " ";
	cout << "Enter Book ID: "; cin >> bookID;
	cout << "Enter Patron ID: "; cin >> patronID;
	cout << "Enter Loan ID: "; cin >> ID;
	currPatron = patronList.findPatron(patronID);
	numBookBorrow = currPatron->getBorrowedbook();
	for (auto it = loanList.begin(); it != loanList.end(); ++it) {
		currLoan = *it;
		if (patronID == currLoan->getPatronID() && bookID == currLoan->getBookID()) {
			if (currLoan->getLoanStatus() == "Overdue") {
				cout << "Patron has overdue book(s)." << endl;
				float balance = (time(0) - dateAndtime) / 86400;
				currPatron->setBalance(balance);
				loanList.erase(it);
			}
			numBookBorrow--;
		}
	}
	currBook->setBookStatus("In");
	loanCount--;
}
/*Report lost
for book lost
patron’s current fine = current fine + cost of book
delete the book from the data
remove book from patron’s list*/

void Loans::lostBook(Books &bookList, Patrons &patronList) {
	cout << "Enter Book ID: " << endl; cin >> bookID;
	cout << "Enter Patron ID: " << endl; cin >> patronID;
	currBook = bookList.findBook(bookID);
	for (auto it = loanList.begin(); it != loanList.end(); ++it) {
		if (bookID == currLoan->getBookID()) {
			bookList.delBook(bookID);
		}
	}
	bookList.decount();
	float fine = currBook->getCost();
	currPatron->setBalance(fine);
}
/*Update loan status with time
If current Dateand Time > check out Dateand Time
Fine value
status = not allowed to check out
else
status = allowed to check out*/

void Loans::bookOverdue() {
	cout << "Overdue book(s) of Patron:\n";
	time_t now = time(0);
	int id;
	bool normal = true;
	time_t dueDate = time(0) + (10 * 24 * 60 * 60);

	cout << "Enter Patron ID: " << endl; cin >> id;

	for (unsigned int i = 0; i < loanList.size(); i++) {
		if (id == loanList[i]->getPatronID()) {
			if (now > dueDate) {
				loanList[i]->printLoan();
				normal = false;
			}
			else {
				cout << "No overdue books for this patron." << endl;
			}
		}
	}
		
}
/*List overdue
In check out Dateand Time
If current time > check out Dateand Time
Print patronand book


List book for patron
Prompt user for Patron name / ID
print book in the patron’s list*/

void Loans::listPatronBook() {
	cout << "Book(s) borrowed by Patron: " << endl;
	int id;
	cout << "Enter Patron ID: "; cin >> id;
	for (auto it = loanList.begin(); it != loanList.end();++it) {
		if (id == (*it)->getLoanID()) {
			(*it)->printLoan();
		}
	}
}
void Loans::updateStatus() {
	time_t now = time(0);
	time_t dueDate = time(0) + (10 * 24 * 60 * 60);
	if (now > dueDate) {
		currLoan->setLoanStatus("Overdue");
	}
	else {
		currLoan->setLoanStatus("Normal");
	}
}
/*Re - check book
Find Patron with name / ID
If overdue books
No check out allowed
Else if total books out <= 6
No check out allowed
else if fines owned
No check out allowed
Else
Update dateand time*/


void Loans::recheckBook(Books& bookList, Patrons& patronList) {
	time_t now = time(0);
	cout << "Enter Book ID: "; cin >> bookID;
	cout << "Enter Patron ID: "; cin >> patronID;
	currPatron = patronList.findPatron(patronID);
	numBookBorrow = currPatron->getBorrowedbook();
	if (numBookBorrow > 6) {
		cout << "Limit reached!" << endl;
	}
	for (auto it = loanList.begin(); it != loanList.end(); ++it) {
		currLoan = *it;
		if (patronID == currLoan->getPatronID() && bookID==currLoan->getBookID()) {
			if (currLoan->getLoanStatus() == "Overdue") {
				currLoan->setLoanStatus("Normal");
				cout << "Patron has overdue book(s)." << endl;
			}
			currLoan->setDueDate(time(0) + (10 * 24 * 60 * 60));
		}
	}
	
}
void Loans::loadLoan() {
	ifstream in;
	int ID, bookID, patronID, dateAndtime; string loanStatus;
	in.open("loans.dat");
	in >> loanCount;
	in.ignore();
	for (int i = 0; i < loanCount; i++) {
		in >> ID >> bookID >> patronID >> dateAndtime >> loanStatus;
		loanList.push_back(new Loan(ID, bookID, patronID, dateAndtime, loanStatus));
	}
	in.close();
}

void Loans::storeLoan() {
	Loan* temp;
	ofstream out;
	out.open("loans.dat");
	out << loanCount << endl;
	for (auto it = loanList.begin(); it != loanList.end(); ++it) {
		temp = *it;
		out << temp->getBookID() << temp->getBookID() << temp->getPatronID() << temp->getDueDate() << temp->getLoanStatus() << endl;
	}
	out.close();
}



