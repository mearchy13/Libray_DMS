#include "patrons.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <ctime>

Patrons::Patrons() { patronCount = 0; }

int Patrons::getcount() { return patronCount; }
void Patrons::incount() { patronCount++; }
void Patrons::decount() { patronCount--; }
/*Add Patron
Prompt user for ID
Prompt user for Name
Create Patron object
Populate object
use object to add data*/

void Patrons::addPatron() {
	string name; int pID; float fine; int borrowed;
	Patron* temp;
	cout << "\nName: "; getline(cin, name);
	cout << "\nID number: "; cin >> pID; cin.ignore();
	cout << "\nFine Balance:"; cin >> fine; cin.ignore();
	cout << "\nNumber of books borrowed: "; cin >> borrowed; cin.ignore();
	cout << endl;
	temp = new Patron(name, pID, fine, borrowed);
	patronList.push_back(temp);
}
/*Edit Patron

update fine balance if past due Dateand Time
update # of books borrowed
 Prompt user for which Patron parameters to change
Prompt user to change that parameter */

void Patrons::editPatron() {
	string name; int pID; float fine; int borrowed; 
	int i = 0;
	char choice;
	cout << "Enter Patron ID to edit: "; cin >> pID; cout<< endl;
	for (int i = 0; i < patronCount; i++) {
		if (patronList[i]->getID() == pID) {
		}
	}
	cout << "EDIT PATRON MENU\na-Edit Name\nb-Edit Patron ID\nc-Edit Patron's Fine\nd-Edit Numbers of borrowed books\n0-exit" << endl;
	cin >> choice; cin.ignore();
	while (choice != 0) {
		switch (choice) {
		case 'a':
			cout << "Change Name to: "; getline(cin, name);
			patronList[i]->setName(name);
			break;
		case 'b':
			cout << "Change Patron ID to: "; cin >> pID; cin.ignore();
			patronList[i]->setID(pID);
			break;
		case 'c':
			cout << "Change fine to: "; cin >> fine; cin.ignore();
			patronList[i]->setBalance(fine);
			break;
		case 'd':
			cout << "Change number of borrowed book to: "; cin >> borrowed; cin.ignore();
			patronList[i]->setBorrowedbook(borrowed);
			break;
		}
	}
}
/*Delete Patron

Prompt user for name or ID
Delete matching data*/


void Patrons::delPatron(int pID) {
	for (auto it = patronList.begin(); it != patronList.end(); ++it) {
		if ((*it)->getID() == pID) {
			patronList.erase(it);
		}
	}
}
/*Search / Find

Prompt user to select search method
If name
Prompt user for name
Search in name database
Find data
If ID
Prompt user for ID
Search in ID database
Find data*/

Patron* Patrons::findPatron(int pID) {
	for (int i = 0; i < patronCount; i++)
	{
		if (patronList[i]->getID() == pID) return patronList[i];
	}
	return NULL;
}
/*Search patron by name

prompt user for name
If name matches data in Patron
Return ID

Search patron by ID

Prompt user for ID
If ID matched any data
Return name

Print patron by name

Prompt user for name
Find patron by name(return ID)
Search info about patron(by ID)
If patron id matches name
Print all info of Patron(including Fine balance and Current # of borrowed book)


Print patron by ID

Prompt user for ID
Search info about Patron(by ID)
If patron ID matches name
Print all info of patron(including Fine balance and Current # of borrowed book)

Print all Patron

Print all info in Patron*/

void Patrons::printPatron() {
	Patron* temp;
	for (auto it = patronList.begin(); it != patronList.end(); ++it) {
		temp = *it;
		cout << "\nName: " << temp->getName() << "\nPatron ID: " << temp->getID() << "\nFine Balance: " << temp->getBalance() << "\nNumber of books borrowed: " << temp->getBorrowedbook() << endl;
	}
}
void Patrons::loadPatron() {
	string name; int pID; float fine; int borrowed;
	ifstream in;
	in.open("patrons.dat");
	in >> patronCount; in.ignore();
	for (int i = 0; i < patronCount; i++) {
		in >> name >> pID >> fine >> borrowed;
		patronList.push_back(new Patron(name, pID, fine, borrowed));
	}
	in.close();
}
void Patrons::storePatron() {
	Patron* temp;
	ofstream out;
	out.open("patrons.dat");
	out << patronCount << endl;
	for (auto it = patronList.begin(); it != patronList.end(); ++it) {
		temp = *it;
		out << temp->getName() << " " << temp->getID() << " " << temp->getBalance() << " " << temp->getBorrowedbook() << endl;
	}
	out.close();
}
void Patrons::payFine() {
	//Fixme
}