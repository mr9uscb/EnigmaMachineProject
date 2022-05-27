#include "Wheel.h"
#include <string>
#include <iostream>
#include <vector>
#include "Plugboard.h"

using namespace std;

/* Constructor */ 
Wheel::Wheel() {
	counter = 0;
} // end wheel constructor

void Wheel::reset() {
	counter = 0;
}

/* Rotates rotor */
int Wheel::rotate( ) {
	string temp = code;

	temp = temp.substr(1, temp.length() - 1) + temp.front();
	code = temp;

	//counter++;
	return counter++;
}

/* Sets the correct rotor to each wheel */
void  Wheel::setCode(int wheel) {
	switch (wheel) {
	case(1): 
		code = Rotor1;
		break;
	case(2):
		code = Rotor2;
		break;
	case(3): 
		code = Rotor3;
		break;
	case(4): 
		code = Rotor4;
		break;
	case(5): 
		code = Rotor5;
		break;
	default: 
		cout << "Invalid choice";
		break;
	}
}

/* Gets index of a character on a rotor */
int Wheel::getIndex(char original) {
	int index;

	index = code.find(original);

	return index;
}

/* Gets character of rotor at certain index */
char Wheel::getCharacter(int position) {
	char currentLetter;

	int i = position;
	currentLetter = code[i];

	return currentLetter;
}

/* Sets the starting position of the rotors */
void Wheel::startPosition() {
	int choice;
	string temp;

	cout << "Enter the starting position: ";
	cin >> choice;
	temp = code;

	temp = temp.substr(choice - 1, temp.length() - (choice - 1));
	temp.append(code, 0, (choice - 1));
	code = temp;

	 //cout << endl << "Rotor after shift: " << code << endl;
}

/* Method returns the code */
string Wheel::getCode() {
	return code;
}








