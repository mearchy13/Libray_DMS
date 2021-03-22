lib: main.o book.o books.o patron.o patrons.o loan.o loans.o
	g++ main.o book.o books.o patron.o patrons.o loan.o loans.o -o lib

main.o: main.cpp
	g++ -c main.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

books.o: books.cpp books.h
	g++ -c books.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

patrons.o: patrons.cpp patrons.h
	g++ -c patrons.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

loans.o: loans.cpp loan.h
	g++ -c loans.cpp