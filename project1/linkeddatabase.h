// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <string>
#include "city.h"

#ifndef LINKED_H
#define LINKED_H

class LinkedDatabase : public Database {
private:
	// Simple Node structure for this linked list.
	struct Node {
		City city;
		Node* next;

		// Ensures proper destruction
		~Node() {
			delete next;
		}
	};

	// Pointer to the beginning of the database.
	Node* head;

public:
	LinkedDatabase() : head(nullptr) { } // Default constructor creates an empty database.

	void insert(City);			 // Inserts a given city into the database.
	void remove(std::string);	 // Removes a city of given name.
	void remove(double, double); // Removes a city of given coords.
	void search(std::string);	 // Searches for a city of given name.
	void search(double, double); // Searches for a city of given coords.
	void withinOf(double, double, double); // Prints any cities within 'dist' units of (lat, lon).
	void print();				 // Prints entire database.
};

#endif // LINKED_H

// EOF
