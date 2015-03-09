// Douglas Keller
// dwk24@zips.uakron.edu
// Data Structures
// Assignment 2

#include <iostream>
#include <string>

using namespace std;

// A string is used so that the # of steps and the key can be found using one value.
// If a string's length == 0, that means there's no solution
// If a string's length > 0, that means there's a solution
string getSolution(int initial, int goal, int increment, int n, int step, string key) {

	// If the max steps has been exceeded, return no solution.
	if(step > n)
		return ""; // No solution

	// If the goal has been met, return the solution;
	if(initial == goal)
		return key; // Return solution string.

	// Gets the solution if step A is taken.
	string stepA = getSolution(initial + increment, goal, increment, n, step + 1, key + "A ");
	string stepB;

	// If the current amount is even, get the solution if step B is taken.
	if(initial % 2 == 0)
		stepB = getSolution(initial / 2, goal, increment, n, step + 1, key + "B ");

	// If A is possible
	if(stepA.length() > 0) {
		// If B is also possible and shorter than A, return B
		if(stepB.length() > 0 && stepB.length() < stepA.length())
			return stepB;
		// Otherwise, return A
		return stepA;
	}
	return stepB; // Otherwise, return B whether it's possible or not.
};

int main() {
	bool running = true;

	while(running) {
		cout << "What would you like to do?\n";
		cout << "   1. Find solution\n";
		cout << "   0. Exit\n";
		cout << "   :: ";

		int input = 0;

		cin >> input;

		switch(input) {
		case 1: {
			int initial, goal, increment, n;
			cout << "  Initial amount: ";
			cin >> initial;
			cout << "      Goal value: ";
			cin >> goal;
			cout << "Increment amount: ";
			cin >> increment;
			cout << " Number of steps: ";
			cin >> n;
			string sol = getSolution(initial, goal, increment, n, 0, "");

			if(sol.length() > 0) // Solution found
				cout << "\n\nSolution in " << sol.length() / 2 << " steps: " << sol << "\n\n";
			else
				cout << "\n\nNo solution.\n\n";
			break;
				}
		case 0:
			running = false;
			break;
		default:
			cout << "Invalid input.\n\n";
			break;
		}
	}
}