#include "Reflector.h"
#include <iostream>
using namespace std;

/* Constructor */
Reflector::Reflector() {

} // end Reflector constructor

/* Prompts user for the wheels that are to be used */
void Reflector::promptUser() {
	cout << "Please enter the reflector settings: " << endl;
	cout << "Opition (1): " << output1 << endl;
	cout << "Opition (2): " << output2 << endl;
	cout << "Opition (3): " << output3 << endl;
	cout << "Your choice: ";
	cin >> choice;

	/* setting the reflectorSetting variable */
	setReflector(choice);

} // end promptUser method

/* Splits the reflector setting in two parts */
void Reflector::splitCharacterString() {

	getReflector(); // output reflectorSetting

	string temp;
	
	for (int i = 0; i < reflectorSetting.size(); i++) {
		if (i % 2 == 0) {
			part1 += reflectorSetting[i];
		}
		else {
			part2 += reflectorSetting[i];
		}
	}

	/* Just for testing to make sure code is working correctly */
	// cout << endl << "String part1: " << part1;
	// cout << endl << "String part2: " << part2;
	// cout << endl;

} // end splitCharacterString method 

/* Sets the reflector settings */
string Reflector::setReflector(int choice) {
	switch (choice) {
	case 1:
		reflectorSetting = reflectorSettings1;
		break;
	case 2:
		reflectorSetting = reflectorSettings2;
		break;
	case 3:
		reflectorSetting = reflectorSettings3;
		break;
	default:
		cout << "Invalid choice";
		break;  
	}

	return reflectorSetting;
}

/* Print out current reflector settings */
void Reflector::getReflector() {
	cout << endl << "Current reflector setting: " << reflectorSetting << endl;
}

/* Method that uses the reflector on characters */
char Reflector::useReflector(char original) {
	bool lower;
	int indexA, indexB;
	char reflected;
	//lower = islower(original);
	//original = toupper(original);
	indexA = part1.find(original);
	indexB = part2.find(original);

	if (indexA >= 0) {
		reflected = part2[indexA];
	}
	else if (indexB >= 0) {
		reflected = part1[indexB];
	}
	else {
		reflected = original;
	}
	cout << endl;

	/* printing out values to make sure they are correct */
	cout << "Letter before it went through the reflector: " << original << endl;
	cout << "letter after it went through the reflector: " << reflected << endl;

	return reflected;
}

/* Method that uses the reflector on characters -- without steps */
char Reflector::useReflectorWithoutSteps(char original) {
	bool lower;
	int indexA, indexB;
	char reflected;
	//lower = islower(original);
	//original = toupper(original);
	indexA = part1.find(original);
	indexB = part2.find(original);

	if (indexA >= 0) {
		reflected = part2[indexA];
	}
	else if (indexB >= 0) {
		reflected = part1[indexB];
	}
	else {
		reflected = original;
	}
	//cout << endl;

	/* printing out values to make sure they are correct */
	// cout << "Letter before it went through the reflector: " << original << endl;
	// cout << "letter after it went through the reflector: " << reflected << endl;

	return reflected;
}