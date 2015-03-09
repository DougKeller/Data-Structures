// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <ctime>
#include "city.h"

#ifndef PROGRAM_H
#define PROGRAM_H

class Program {
private:
	bool runtime;
	std::clock_t timer;

	void run(Database*);
	void insert(Database*);
	void searchName(Database*);
	void searchCoord(Database*);
	void removeName(Database*);
	void removeCoord(Database*);
	void showWithin(Database*);
	void printAll(Database*);

	void runComparison();

public:
	void start();
};

#endif // PROGRAM_H

// EOF