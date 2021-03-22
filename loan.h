#ifndef LOAN_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Loan {
public:
	Loan();
	Loan(int ID, int bookID, int patronID,int dateAndtime, string loanStatus);
	void setLoanID(int ID);
	int getLoanID();
	void setBookID(int bookID);
	int getBookID();
	void setPatronID(int patronID);
	int getPatronID();
	void setDueDate(int dateAndTime);
	int getDueDate();
	string getLoanStatus();
	void setLoanStatus(string loanStatus);

	void printLoan();
private:
	int loanID;
	int loanBookID;
	int loanPatronID;
	int dueDate;
	string currLoanStatus;
};

#endif