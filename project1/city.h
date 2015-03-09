// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <iostream>
#include <string>
#include <cmath>

#ifndef CITY_H
#define CITY_H

// The basic City struct to be used
// for both database implementations.
struct City {
	std::string name;
	double lat, lon;

	// Calculates the distance in miles to a given x/y coordinate using the given formula:
	// e = ARCCOS[ SIN(LAT1)*SIN(LAT2) + COS(LAT1)*COS(LAT2)*COS(LONG2-LONG1) ]
	double distanceTo(double lat2, double lon2) const {
		double e = std::acos( std::sin(lat) * std::sin(lat2) + std::cos(lat) * std::cos(lat2) * std::cos(lon2 - lon) );
		return e * 3963.191; // Distance in miles
	}

	// Convenient method that accepts a constant reference to a City.
	double distanceTo(City const& c) const {
		return distanceTo(c.lat, c.lon);
	}

	// Print information.
	void print() {
		std::cout << name << ", (" << lat << ',' << lon << ")\n";
	}

	// == Comparator function.
	bool operator==(City& city) {
		return name == city.name && lat == city.lat && lon == city.lon;
	}
};


// Pure abstract parent class for other database classes.
struct Database {	
	virtual void insert(City) = 0;			 // Inserts a given city into the database.
	virtual void remove(std::string) = 0;	 // Removes a city of given name.
	virtual void remove(double, double) = 0; // Removes a city of given coords.
	virtual void search(std::string) = 0;	 // Searches for a city of given name.
	virtual void search(double, double) = 0; // Searches for a city of given coords.
	virtual void withinOf(double, double, double) =  0; // Prints any cities within 'dist' units of (lat, lon).
	virtual void print() = 0;				 // Prints entire database.
};

#endif // CITY_H

// EOF