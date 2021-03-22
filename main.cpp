//Shyam Nath
//CSCE 1040
//Homework 3

#include "loans.h"
#include "books.h"
#include "patrons.h"

using namespace std;

Loans loans;
Books books;
Patrons patrons;
int main() {
	int id = 0;
	char choice1=' ', choice2=' ', choice3=' ', choice4=' ';

	books.loadBook();
	patrons.loadPatron();
	loans.loadLoan();

	cout << "Welcome to Public Library Database\n" << endl;
	while (choice1 != 'x') {
		cout << "MENU\n" << endl;
		cout << "Choose one:\n"; cout << "p-Patron\nb-Book\nl-Loan\nx-exit\n";
		cin >> choice1;
		switch (choice1) {
		case 'p':
			while (choice2 != 'x') {
				cout << "PATRON MENU\n";
				cout << "a-Add Patron\ne-Edit Patron\nd-Delete Patron\nf-find Patron\np-Print Patron\ny-Pay Fines\nx-exit\n";
				cin >> choice2;
				switch (choice2) {
				case 'a': patrons.addPatron(); break;
				case 'e':patrons.editPatron(); break;
				case 'd': {
					cout << "Enter ID of Patron to delete: ";
					cin >> id; cin.ignore();
						patrons.delPatron(id);
					break;
				}
				case 'f': {
					cout << "Search from Patron ID: ";
					cin >> id; cin.ignore();
					patrons.findPatron(id);
					break;
				}
				case 'p':patrons.printPatron(); break;
				case 'y':patrons.payFine(); break;
				}
			}
		case 'b':
			while (choice3 != 'x') {
				cout << "BOOK MENU\n";
				cout << "a-Add Book\ne-Edit Book\nd-Delete Book\nf-find Book\np-Print Book\nx-exit\n";
				cin >> choice3;
				switch (choice3) {
				case 'a': books.addBook(); break;
				case 'e':books.editBook(); break;
				case 'd': {
					cout << "Enter ID of Book to delete: ";
					cin >> id; cin.ignore();
					books.delBook(id);
					break;
				}
				case 'f': {
					cout << "Search from Book ID: ";
					cin >> id; cin.ignore();
					books.findBook(id);
					break;
				}
				case 'p':books.printBook(); break;
				}
			}
		case 'l':
			while (choice4 != 'x') {
				cout << "LOAN MENU\n";
				cout << "o-Check-out Book\ni-Check-in Book\nr-Re-check Book\nv-List Overdue\nl-List Book for Patron\ne-Report Lost\nx-exit\n";
				cin >> choice4; cin.ignore();
				switch (choice4) {
				case'o':loans.bookOut(books, patrons); break;
				case'i':loans.bookIn(books, patrons); break;
				case'r':loans.recheckBook(books, patrons); break;
				case'v':loans.bookOverdue(); break;
				case'l':loans.listPatronBook(); break;
				case'e':loans.lostBook(books, patrons); break;
				}
			}
		}
	
	}
}