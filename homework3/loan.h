#ifndef PATRON_H
#include <iostream>
#include <string>

using namespace std;

class Loan {
public:
	Loan();
	Loan(int loanID, int bookID, int patronID,int dateAndtime, string loanStaus);
	int setLoanID();
	int getLoanID();
	int setBookID();
	int getBookID();
	int setPatronID();
	int getPatronID();
	int setDueDate();
	int getDueDate();
	string getLoanStatus();
	string setLoanStatus();
private:
	int loanID;
	int loanBookID;
	int loanPatronID;
	int dueDate;
	string currLoanStaus;
};

#endif