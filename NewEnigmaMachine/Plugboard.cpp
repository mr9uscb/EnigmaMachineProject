#include "Plugboard.h"
#include <string>
#include <iostream>
using namespace std;

/* Constructor */
Plugboard::Plugboard() {

} // end plugboard constructor

/* Prompts user for the wheels that are to be used */
void Plugboard::promptUser() {
	cout << "Please enter the plugboard setting characters: ";
	cin.ignore();
	getline(cin, plugboardSettingString);
} // end promptUser method

/* Splits the string into two parts */
void Plugboard::splitCharacterString() {
	while (counter != 1) {
		for (int i = 0; i < plugboardSettingString.size(); i++) {
			if ((isalpha(plugboardSettingString[i]))) {
				plugboardSetting += plugboardSettingString[i];
			}
			else if (isblank(plugboardSettingString[i])) {

			}
		} // end for loop

		counter++;

		/* testing result to make sure it works */
		// cout << endl << "The inputted settings without spaces is: " << plugboardSetting << endl;

	} // end while loop


	for (int i = 0; i < plugboardSetting.size(); i++) {
		if (i % 2 == 0) {
			part1 += plugboardSetting[i];
		}
		else {
			part2 += plugboardSetting[i];
		}
	}

	/* Testing to make sure output is correct */
	// cout << endl << "String part1: " << part1;
	// cout << endl << "String part2: " << part2;
	cout << endl;

} // end splitCharacterString method 

/* Returns part 1 and part 2 of the characterString */
string Plugboard::getSplitCharacterString() {
	return part1;
	return part2;
} // end getSplitCharacterString method

/* Uses plugboard setting on the message */
char Plugboard::usePlug(char original) {
	bool lower;
	int indexA, indexB;
	char plugged;
	//lower = islower(original);
	//original = toupper(original);
	indexA = part1.find(original);
	indexB = part2.find(original);
	
	/*
	need to have the two parts go against each other so that the plugboard functions 
	as it should 
	*/
	if (indexA >= 0) {
		plugged = part2[indexA];
	}
	else if (indexB >= 0) {
		plugged = part1[indexB];
	}
	else {
		plugged = original;
	}
	cout << endl;

	/* printing out values to make sure they are correct */
	cout << "Letter before it went through the plugboard: " << original << endl;
	cout << "letter after it went through the plugboard: " << plugged << endl;

	return plugged;
}

/* Uses plugboard setting on the message -- without steps */
char Plugboard::usePlugWithoutSteps(char original) {
	bool lower;
	int indexA, indexB;
	char plugged;
	//lower = islower(original);
	//original = toupper(original);
	indexA = part1.find(original);
	indexB = part2.find(original);

	/*
	need to have the two parts go against each other so that the plugboard functions
	as it should
	*/
	if (indexA >= 0) {
		plugged = part2[indexA];
	}
	else if (indexB >= 0) {
		plugged = part1[indexB];
	}
	else {
		plugged = original;
	}
	//cout << endl;

	/* printing out values to make sure they are correct */
	// cout << "Letter before it went through the plugboard: " << original << endl;
	// cout << "letter after it went through the plugboard: " << plugged << endl;

	return plugged;
}