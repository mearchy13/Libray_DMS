#ifndef LOANS_H
#define LOANS_H
#include <vector>
#include "loan.h"
#include "books.h"
#include "patrons.h"

class Loans {
public:
	Loans();
	void inLoan();
	void deLoan();
	void bookOut(Books& bookList, Patrons& patronList);
	void bookIn(Books& bookList, Patrons& patronList);
	void bookOverdue();
	void listPatronBook();
	void updateStatus();
	void recheckBook(Books& bookList, Patrons& patronList);
	void lostBook(Books& bookList, Patrons& patronList);
	void loadLoan();
	void storeLoan();
private:
	int loanCount;
	vector <Loan*> loanList;
};
#endif
