// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <iostream>
#include <string>
#include "city.h"
#include "linkeddatabase.h"

// Inserts a given city into the database.
void LinkedDatabase::insert(City city) {
	// Check if database already contains city.
	Node* pos = head;
	while(pos) {
		// If the same city is found, return.
		if(pos->city == city) {
			std::cout << "No need to insert again, as this record exists in the existing data set.\n";
			return;
		}

		// Increment to the next city.
		pos = pos->next;
	}

	// If loop exits, database does not contain city. Create a new node to contain it.
	Node* newNode = new Node;
	newNode->city = city;
	newNode->next = nullptr;

	// Add the new node to the end of the database, or assign it to head and tail if database is empty.
	if(!head) {
		head = newNode;
	} else {
		// Iterate to the end of the list
		Node* pos = head;

		while(pos->next)
			pos = pos->next;

		pos->next = newNode;
	}
	
	std::cout << "Record inserted successfully.\n";
}

// Removes a city of given name.
void LinkedDatabase::remove(std::string name) {

	// If database is empty, return.
	if(!head) {
		std::cout << "No such record exists in the existing data set.\n";
		return;
	}

	// If the head matches the name, delete it.
	if(head->city.name == name) {
		Node* temp = head;
		head = head->next;

		// Setting temp's next to nullptr prevents the entire list from deconstructing.
		temp->next = nullptr; 
		delete temp;
		std::cout << "Deleted successfully.\n";
		return;
	}

	// Iterate until a match is found.
	Node* pos = head;
	while(pos->next) {
		// If pos->next matches, delete pos->next
		if(pos->next->city.name == name) {
			// Temporary pointer for pos->next
			Node* temp = pos->next;
			
			// Skip over the city to be deleted.
			pos->next = pos->next->next;

			// Prevent entire list deconstruction.
			temp->next = nullptr;
			delete temp;

			std::cout << "Deleted successfully.\n";
			return;
		}

		// If no match found, increment pos.
		pos = pos->next;
	}

	// If the loop ends, no match was found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Removes a city of given coords.
void LinkedDatabase::remove(double lat, double lon) {

	// If database is empty, return.
	if(!head) {
		std::cout << "No such record exists in the existing data set.\n";
		return;
	}

	// If the head matches the name, delete it.
	if(head->city.lat == lat && head->city.lon == lon) {
		Node* temp = head;
		head = head->next;

		// Setting temp's next to nullptr prevents the entire list from deconstructing.
		temp->next = nullptr;
		delete temp;
		std::cout << "Deleted successfully.\n";
		return;
	}

	// Iterate until a match is found.
	Node* pos = head;
	while(pos->next) {
		// If pos->next matches, delete pos->next
		if(pos->next->city.lat == lat && pos->next->city.lon == lon) {
			// Temporary pointer for pos->next
			Node* temp = pos->next;
			
			// Skip over the city to be deleted.
			pos->next = pos->next->next;

			// Prevent entire list deconstruction.
			temp->next = nullptr;
			delete temp;

			std::cout << "Deleted successfully.\n";
			return;
		}

		// If no match found, increment pos.
		pos = pos->next;
	}

	// If the loop ends, no match was found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Searches for a city of given name.
void LinkedDatabase::search(std::string name) {
	// Iterator
	Node* pos = head;
	
	// Search for city that matches
	while(pos) {
		if(pos->city.name == name) {
			pos->city.print();
			return;
		}

		pos = pos->next;
	}

	// Not found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Searches for a city of given coords.
void LinkedDatabase::search(double lat, double lon) {
	// Iterator
	Node* pos = head;
	
	// Search for city that matches
	while(pos) {
		if(pos->city.lat == lat && pos->city.lon == lon) {
			pos->city.print();
			return;
		}

		pos = pos->next;
	}

	// Not found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Prints any cities within 'dist' units of (lat, lon).
void LinkedDatabase::withinOf(double dist, double lat, double lon) {
	bool found = false; // Tracks whether a result has been found. Used for output.

	// Iterator
	Node* pos = head;
	
	// Iterate through entire database, printing any valid cities.
	while(pos) {
		if(pos->city.distanceTo(lat, lon) <= dist) {
			pos->city.print();
			found = true;
		}

		pos = pos->next;
	}

	if(!found)
		std::cout << "No such record exists in the existing data set.\n";
}

// Prints entire database.
void LinkedDatabase::print() {
	Node* pos = head;
	while(pos) {
		pos->city.print();
		pos = pos->next;
	}
}

// EOF