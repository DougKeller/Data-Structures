// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <string>
#include "city.h"

#ifndef ARRAY_H
#define ARRAY_H

class ArrayDatabase : public Database {
private:
	int size;	  // Size of the database.
	City* cities; // Simple array containing all cities in this database.

public:
	ArrayDatabase() : size(0), cities(new City[0]) { } // Default constructor creates an empty database.

	void insert(City);			 // Inserts a given city into the database.
	void remove(std::string);	 // Removes a city of given name.
	void remove(double, double); // Removes a city of given coords.
	void search(std::string);	 // Searches for a city of given name.
	void search(double, double); // Searches for a city of given coords.
	void withinOf(double, double, double); // Prints any cities within 'dist' units of (lat, lon).
	void print();				 // Prints entire database.
};

#endif // ARRAY_H

// EOF