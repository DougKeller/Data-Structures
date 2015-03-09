// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <iostream>
#include <string>
#include "arraydatabase.h"
#include "city.h"

// Inserts a given city into the database.
void ArrayDatabase::insert(City city) {
	// Create a new array that's one longer than the previous database.
	City* newCities = new City[size+1];

	// Copy contents to new array.
	for(int i = 0; i < size; ++i) {
		// If the city to be added is already in the database
		if(cities[i] == city) {
			// Delete the new database, display a message and return.
			delete [] newCities;
			std::cout << "No need to insert again, as this record exists in the existing data set.\n";
			return;
		}

		newCities[i] = cities[i];
	}

	// Increment size.
	size++;

	// Add the new city to the end of the new database.
	newCities[size - 1] = city;

	// Delete the old database and replace it with the new.
	delete [] cities;
	cities = newCities;

	std::cout << "Record inserted successfully.\n";
}

// Removes a city of given name.
void ArrayDatabase::remove(std::string name) {
	// Index of the city to be deleted.
	int index;

	// Iterate until a match is found.
	for(index = 0; index < size; ++index) {
		// If a matching name is found, leave the loop.
		if(cities[index].name == name)
			break;
	}

	// If index == size, the name was not found. In  this case, return.
	if(index == size) {
		std::cout << "No such record exists in the existing data set.\n";
		return;
	}

	// Create a new array that's one shorter than the previous database
	City* newCities = new City[size - 1];

	// Copy all cities except the deleted one.
	for(int i = 0; i < size; ++i) {
		if(i != index) {
			// If the current position is higher in the old database than the deleted city
			if(i > index)
				// Decrement the index and use that value to copy to the new array.
				newCities[i - 1] = cities[i];
			else
				newCities[i] = cities[i];
		}
	}

	// Decrement size.
	size--;

	// Delete the old database and replace it with the new.
	delete [] cities;
	cities = newCities;

	std::cout << "Deleted successfully.\n";
}

// Removes a city of given coords.
void ArrayDatabase::remove(double lat, double lon) {
	// Index of the city to be deleted.
	int index;

	// Iterate until a match is found.
	for(index = 0; index < size; ++index) {
		// If a matching coord is found, leave the loop.
		if(cities[index].lat == lat && cities[index].lon == lon)
			break;
	}

	// If index == size, the coords were not found. In  this case, return.
	if(index == size) {
		std::cout << "No such record exists in the existing data set.\n";
		return;
	}

	// Create a new array that's one shorter than the previous database
	City* newCities = new City[size - 1];

	// Copy all cities except the deleted one.
	for(int i = 0; i < size; ++i) {
		if(i != index) {
			// If the current position is higher in the old database than the deleted city
			if(i > index)
				// Decrement the index and use that value to copy to the new array.
				newCities[i - 1] = cities[i];
			else
				newCities[i] = cities[i];
		}
	}

	// Now that copying to the smaller array is complete, decrement the database's size.
	size--;

	// Delete the old database and replace it with the new.
	delete [] cities;
	cities = newCities;

	std::cout << "Deleted successfully.\n";
}

// Searches for a city of given name.
void ArrayDatabase::search(std::string name) {
	// Iterate through array until a match is found.
	for(int i = 0; i < size; ++i)
		// If a match is found
		if(cities[i].name == name) {
			// print the city and return.
			cities[i].print();
			return;
		}

	// If the for loop exits, the city was not found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Searches for a city of given coords.
void ArrayDatabase::search(double lat, double lon) {
	// Iterate through array until a match is found.
	for(int i = 0; i < size; ++i)
		// If a match is found
		if(cities[i].lat == lat && cities[i].lon == lon) {
			// print the city and return.
			cities[i].print();
			return;
		}

	// If the for loop exits, the city was not found.
	std::cout << "No such record exists in the existing data set.\n";
}

// Prints any cities within 'dist' units of (lat, lon).
void ArrayDatabase::withinOf(double dist, double lat, double lon) {
	bool found = false; // Tracks whether a result has been found. Used for output.

	// Iterate through entire database, printing any valid cities.
	for(int i = 0; i < size; ++i)
		if(cities[i].distanceTo(lat, lon) <= dist) {
			cities[i].print();
			found = true;
		}

	if(!found)
		std::cout << "No such record exists in the existing data set.\n";
}

// Prints entire database.
void ArrayDatabase::print() {
	for(int i = 0; i < size; ++i)
		cities[i].print();
}

// EOF