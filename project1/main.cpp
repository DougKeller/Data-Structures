// Douglas Keller
// Data Structures
// Assignment 1
// dwk24@zips.uakron.edu

#include <iostream>
#include <string>
#include <ctime>
#include "city.h"
#include "arraydatabase.h"
#include "linkeddatabase.h"
#include "program.h"

using namespace std;

int main() {
	Program p;
	p.start();
}

void Program::start() {
	bool runningProgram = true;
	runtime = true; // When true, output will contain runtime information.

	while(runningProgram) {
		cout << "Implementation Options:\n";
		cout << "1. Use an array-based list implementation\n";
		cout << "2. Use a linked-list implementation\n";
		cout << "3. Toggle runtime info (currently " << (runtime ? "on)\n" : "off)\n");
		cout << "0. Exit\n::";
		int opt;
		cin >> opt;
		cin.ignore(0);

		cout << "\n\n";

		switch(opt) {
			case 0:
				runningProgram = false;
				break;
			case 1:
				run(new ArrayDatabase());
				break;
			case 2:
				run(new LinkedDatabase());
				break;
			case 3:
				runtime = !runtime;
				cout << "Runtime is now " << (runtime ? "on\n" : "off\n");
				break;
			default:
				cout << "Invalid input.\n\n";
				break;
		}
	}
}

void Program::run(Database* db) {
	bool running = true;

	while(running) {
		cout << "Operation Options:\n";
		cout << "1. Insert a record\n";
		cout << "2. Search for a record by name\n";
		cout << "3. Search for a record by coordinate\n";
		cout << "4. Delete a record by name\n";
		cout << "5. Delete a record by coordinate\n";
		cout << "6. Print records within a given distance of a specified location\n";
		cout << "7. Print all records\n";
		cout << "8. Exit\n::";

		int opt;
		cin >> opt;
		cin.ignore(0);

		cout << "\n\n";

		switch(opt) {
		case 1:
			insert(db);
			break;
		case 2:
			searchName(db);
			break;
		case 3:
			searchCoord(db);
			break;
		case 4:
			removeName(db);
			break;
		case 5:
			removeCoord(db);
			break;
		case 6:
			showWithin(db);
			break;
		case 7:
			printAll(db);
			break;
		case 8:
			running = false;
			break;
		default:
			cout << "Invalid input.\n\n";
			break;
		}
	}
	cout << "\n\n";
}

void Program::insert(Database* db) {
	string name;
	double lat, lon;

	cout << "Enter the name of the new city: ";
	cin >> name;
	cin.ignore(0);

	cout << "Enter the latitude: ";
	cin >> lat;
	cin.ignore(0);
	
	cout << "Enter the longitude: ";
	cin >> lon;
	cin.ignore(0);

	cout << "\n\n";

	City city;
	city.name = name;
	city.lat = lat;
	city.lon = lon;

	if(runtime)
		timer = clock();
	
	db->insert(city);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::searchName(Database* db) {
	string name;

	cout << "Enter name to be searched: ";
	cin >> name;
	cin.ignore();

	cout << "\n\nOutput:\n";
	
	if(runtime)
		timer = clock();
	
	db->search(name);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::searchCoord(Database* db) {
	double lat, lon;

	cout << "Enter latitude to be searched: ";
	cin >> lat;
	cin.ignore(0);

	cout << "Enter longitude to be searched: ";
	cin >> lon;
	cin.ignore(0);

	cout << "\n\nOutput:\n";
	
	if(runtime)
		timer = clock();

	db->search(lat, lon);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::removeName(Database* db) {
	string name;

	cout << "Enter name to be removed: ";
	cin >> name;
	cin.ignore(0);

	cout << "\n\n";
	
	if(runtime)
		timer = clock();

	db->remove(name);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::removeCoord(Database* db) {
	double lat, lon;

	cout << "Enter latitude of point to be removed: ";
	cin >> lat;
	cin.ignore(0);

	cout << "Enter longitude of point to be removed: ";
	cin >> lon;
	cin.ignore(0);
	
	cout << "\n\n";
	
	if(runtime)
		timer = clock();

	db->remove(lat, lon);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::showWithin(Database* db) {
	double dist, lat, lon;

	cout << "Enter latitude: ";
	cin >> lat;
	cin.ignore(0);

	cout << "Enter longitude: ";
	cin >> lon;
	cin.ignore(0);

	cout << "Enter distance: ";
	cin >> dist;
	cin.ignore(0);

	cout << "\n\nOutput:\n";

	if(runtime)
		timer = clock();

	db->withinOf(dist, lat, lon);

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

void Program::printAll(Database* db) {
	cout << "\n\nOutput:\n";

	if(runtime)
		timer = clock();

	db->print();

	if(runtime)
		cout << "Runtime " << (clock() - timer) / (double) CLOCKS_PER_SEC * 1000  << "ms\n";

	cout << "\n\n";
}

// EOF