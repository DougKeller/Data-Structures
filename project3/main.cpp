// Douglas Keller
// dwk24@zips.uakron.edu
// Data Structures
// Programming Assignment 3
// 31 March 2015

#include <iostream>
#include "bst.h"

using namespace std;

int main() {

	bool running = true;

	BST tree;

	while(running) {
		cout << "Enter an option:\n";
		cout << "    0. Search\n";
		cout << "    1. Insert\n";
		cout << "    2. Remove\n";
		cout << "    3. Height\n";
		cout << "    4. Find depth\n";
		cout << "    5. Find highest cost\n";
		cout << "    6. Balanced?\n";
		cout << "    7. In-order\n";
		cout << "    8. Reverse-order\n";
		cout << "    9. Pre-order\n";
		cout << "   10. Post-order\n";
		cout << "    Other: Exit\n";
		cout << " :: ";
		
		int opt;
		cin >> opt;

		cout << "\n\n";

		switch(opt) {
		case 0: {
			cout << "Enter value to search for: ";
			int val;
			cin >> val;
			cout << "Contains " << val << "? " << std::boolalpha << tree.contains(val);
			break;
				}
		case 1: {
			cout << "Enter value to insert: ";
			int val;
			cin >> val;
			tree.insert(val);
			break;
				}
		case 2: {
			cout << "Enter value to remove: ";
			int val;
			cin >> val;
			tree.remove(val);
			break;
				}
		case 3: {
			cout << "Height: " << tree.height();
			break;
				}
		case 4: {
			cout << "Enter value to find depth of that value's corresponding node: ";
			int val;
			cin >> val;
			cout << "Depth of " << val << ": " << tree.depthOf(val);
			break;
				}
		case 5: {
			cout << "Highest cost: " << tree.highestCost();
			break;
				}
		case 6: { 
			cout << "Balanced? " << std::boolalpha << tree.balanced();
			break;
				}
		case 7: {
			tree.print();
			break;
				}
		case 8: {
			tree.printReverse();
			break;
				}
		case 9: {
			tree.printPre();
			break;
				}
		case 10:{
			tree.printPost();
			break;
				}
		default: {
			running = false;
			break;
				 }
		}

		cout << "\n\n";
	}
}