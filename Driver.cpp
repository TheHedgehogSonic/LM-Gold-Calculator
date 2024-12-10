#include <iostream>
#define NOMINMAX // For some reason, ONLY works after iostream inclusion
#include <tuple>
#include "Windows.h"

using namespace std;

typedef unsigned short POS;
typedef unsigned int POS32;

POS i;
POS response;
tuple<string, POS, POS, POS, POS32> Treasure[12]; // Name, value, color, number
POS32 grandTotal;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(POS color);
void getInput();

int main() { // Resume here
	Treasure[0] = { "Coin", 5, 14, 0, 0 };
	Treasure[1] = { "Bill", 20, 2, 0, 0 };
	Treasure[2] = { "Gold Bar", 100, 6, 0, 0 };
	Treasure[3] = { "Small Pearl", 50, 13, 0, 0 };
	Treasure[4] = { "Medium Pearl", 100, 13, 0, 0 };
	Treasure[5] = { "Big Pearl", 1000, 13, 0, 0 };
	Treasure[6] = { "Sapphire", 500, 9, 0, 0 };
	Treasure[7] = { "Emerald", 800, 10, 0, 0 };
	Treasure[8] = { "Ruby", 1000, 12, 0, 0 };
	Treasure[9] = { "Diamond", 2000, 7, 0, 0 };
	Treasure[10] = { "Blood Diamond", 5, 4, 0, 0 };
	Treasure[11] = { "Gold Diamond", 20000, 6, 0, 0 };
	// Phase 1, Inputs
	for (i = 0; i < 12; i++) {
		setColor(get<2>(Treasure[i]));
		cout << "Input number of " << get<0>(Treasure[i]) << "(s): " << flush;
		getInput();
		get<3>(Treasure[i]) = response;

		get<4>(Treasure[i]) = get<3>(Treasure[i]) * get<1>(Treasure[i]);
		grandTotal += get<4>(Treasure[i]);
	}
	
	cout << "\n";
	// Phase 2, Outputs
	for (i = 0; i < 12; i++) {
		setColor(get<2>(Treasure[i]));
		cout << get<0>(Treasure[i]) << " total: " << get<3>(Treasure[i]) << " * value " << get<1>(Treasure[i])
			<< "K = " << get<4>(Treasure[i]) << "K" << endl;
	}

	setColor(15);
	cout << "\nYour GRAND TOTAL is... " << grandTotal << "K! " << endl;
	system("pause");

	return 0;
}

void setColor(POS color) {
	SetConsoleTextAttribute(h, color);
}

void getInput() {
	setColor(3);
	cin >> response;

	while (!cin) { // cin.fail() checks for input mismatches
		cin.clear(); // Clear the bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Only works with NOMIXMAX definition
		setColor(4);
		cout << "Please enter a positive number or 0: " << flush;
		setColor(3);
		cin >> response;
	}
}
