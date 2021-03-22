#include "loan.h"

Loan::Loan() {
	loanID = 0; loanBookID = 0; loanPatronID = 0; dueDate = 0; currLoanStatus = " ";
}
Loan::Loan(int ID, int bookID, int patronID, int dateAndtime, string loanStatus) {
	loanID = ID; loanBookID = bookID; loanPatronID = patronID; dueDate = dateAndtime; currLoanStatus = loanStatus;
}
void Loan::setLoanID(int ID) { loanID = ID; }
int Loan::getLoanID(){ return loanID; }
void Loan::setBookID(int bookID) { loanBookID = bookID; }
int Loan::getBookID() { return loanBookID; }
void Loan::setPatronID(int patronID) { loanPatronID = patronID; }
int Loan::getPatronID() { return loanPatronID; }
void Loan::setDueDate(int dateAndTime) { dueDate = dateAndTime; }
int Loan::getDueDate() { return dueDate; }
string Loan::getLoanStatus() { return currLoanStatus; }
void Loan::setLoanStatus(string loanStatus) { currLoanStatus = loanStatus; }
void Loan::printLoan() {
	cout << "Loan ID: " << loanID << "\nBook ID: " << loanBookID << "\nPatron ID: " << loanPatronID << "\nDue Date: " << dueDate << "\nLoan Status: " << currLoanStatus << endl;
}