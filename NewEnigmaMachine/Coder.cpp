#include "Coder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>
using namespace std;

/* Constructor */
Coder::Coder() {
	promptUser();
} // end coder constructor

/* Method opens the output file */ 
void Coder::openOutputFile() {
	/* Prompts the user for the name of the file to save the result to */
	cout << endl << "Please enter the file name to save the result: ";
	cin >> outFile;
	encryptFile.open(outFile);
	message = getMessage();

	/* Start testing */
	cout << endl<<endl<<message<<endl<<endl;
	cout << newMessage << endl;
	/* End testing */

	encryptFile << newMessage;

} // end openOutputFile method

/* Closes the file that was opened */
void Coder::closeFile() {
	codeFile.close();
}

/* Closes the output file that was opened */
void Coder::closeOutputFile() {
	encryptFile.close();
}

/* Prompts and sets the plugboard settings */
void Coder::getPlugboardSettings() {
	plugboard.promptUser(); // prompts user for the plugboard setting string

	plugboard.splitCharacterString(); // splits the setting string into two variables
	cout << endl;
}

/* Prompts and sets the reflector settings */
void Coder::getReflectorSettings() {
	reflector.promptUser(); // prompts user for the plugboard setting string

	reflector.splitCharacterString(); // splits the setting string into two variables
	cout << endl;
}

/* Kicks off the program */
void Coder::promptUser() {
	cout << "Welcome to the Enigma Machine" << endl;
	openFile(); // opens the file 
	cout << endl;
	cout << "The message is: " << getMessage(); // gets the message
	cout << endl << endl;
	closeFile(); // closes file

	cout << "Run enigma machine: Show steps(1) or show without steps(2)  ";
	cin >> choice;

	cout << endl;
	getPlugboardSettings(); // input plugboard settings 

	getReflectorSettings();
	getWheels();

	if (choice == 1) {
		runMachine();
	}
	else if (choice == 2) {
		runMachineWithoutSteps();
	}
	else {
		cout << "Invalid Choice";
	} // end if-else 
	
}

/* Wheels foward position */
char Coder::wheelsForward(char original) {
	int position;
	char converted;
	cout << original;

	/* Inner Rotor */
	position = inner.getIndex(original);
	// cout << "Inner wheel index: ";
	cout << " -> ";
	cout << position;
	//cout << position << endl;

	/* Outer Rotor */
	converted = outer.getCharacter(position);
	//cout << "Outer wheel character: ";
	//cout << converted << endl;
	cout << " -> " << converted;

	/* Middle Rotor */
	position = middle.getIndex(converted);
	//cout << "Middle wheel index: ";
	//cout << position << endl;
	cout << " -> " << position;

	/* Outer Rotor */
	converted = outer.getCharacter(position);
	//cout << "Outer wheel character: ";
	//cout << converted << endl;
	cout << " -> " << converted;


	cout << endl << endl;
	return converted;

}

/* Wheels reverse position */
char Coder::wheelsReverse(char original) {
	int position;
	char converted;

	cout << original;

	/* Outer Rotor */
	position = outer.getIndex(original);
	cout << " -> " << position;

	/* Middle Rotor */
	converted = middle.getCharacter(position);
	cout << " -> " << converted;

	/* Outer Rotor */
	position = outer.getIndex(converted);
	cout << " -> " << position;

	/* Inner Rotor */
	converted = inner.getCharacter(position);
	cout << " -> " << converted;

	cout << endl << endl;
	return converted;

}

/* Prompts the user and sets the wheels */
void Coder::getWheels() {
	cout << endl;
	int choice;

	/* inner wheel */
	cout << "Please enter the inner wheel number: ";
	cin >> choice;
	cout << endl;
	inner.setCode(choice);
	cout << "Inner wheel: " << inner.getCode() << endl << endl;
	inner.startPosition();

	/* middle wheel */
	cout << endl << "Please enter the middle wheel number: ";
	cin >> choice;
	cout << endl;
	middle.setCode(choice);
	cout << "Middle wheel: " << middle.getCode() << endl << endl;
	middle.startPosition();

	/* outer wheel */
	cout << endl << "Please enter the outer wheel number: ";
	cin >> choice;
	cout << endl;
	outer.setCode(choice);
	cout << "Outer wheel: " << inner.getCode() << endl << endl;
	outer.startPosition();
}

/* Opens file */
void Coder::openFile() {
	/* Prompts the user for the file that needs to be encoded or decoded */
	cout << "Please enter the name of the file to encode/decode: ";
	cin >> inFile;
	//cout << endl << "trying to open " << inFile << endl;
	codeFile.open(inFile);

	/* Exit program if the file cannot be opened */
	if (!codeFile) {
		cerr << "File could not be opened because the sky is falling" << endl;
		exit(EXIT_FAILURE);
	} // end if 

	/* Read in the file and assign it to the variable message */
	while (getline(codeFile, stringIn)) {
		message += stringIn;
	}

	setMessage(message);

	/* just to print to make sure output is correct*/
	// printMessage();
}

/* Encrypting and decrypting */
void Coder::runMachine() {
	int index;
	int count = 0;
	char decrypt;
	bool lower = false;
	string beforePlug;
	string temp;
	string final;

	for (int i = 0; i < message.size(); i++) {
		temp += toupper(message[i]);
	}
	message = temp;
	cout << endl << "The message is: " << message;

	/* take the message and input into a vector */ 
	vector <char> lettersInput(message.begin(), message.end());

	/* print vector out */
	for (int i = 0; i < lettersInput.size(); i++) {
		/* just to make sure the code inputted is correct*/
		//cout << lettersInput[i];
	}



	for (auto letter : lettersInput) {

		/* take the char and plug it into the plugboard */
		decrypt = plugboard.usePlug(letter); // plugs the character into the plugboard

		/* lower the output character */
		//inner = islower(decrypt); // makes the letter lowercase

		/* prints the letter after it was inserted into the plugboard*/
		cout << "after plug: " << decrypt << endl; // prints the character after its inserted into the plugboard

		if (islower(decrypt)) {
			decrypt = toupper(decrypt);
		}

		if (isalpha(decrypt) || decrypt == ' ' || decrypt == '.') {

			/* wheels foward*/
			decrypt = wheelsForward(decrypt);

			/* reflector */
			decrypt = reflector.useReflector(decrypt);

			/* wheels reverse */
			decrypt = wheelsReverse(decrypt);

			/* plugboard again */
			decrypt = plugboard.usePlug(decrypt); // plugs the character into the plugboard
			cout << endl << decrypt << endl;
			count = inner.rotate();
			if (count >= 26) {
				inner.reset();
				count = middle.rotate();
				count = 0;
			}
			if (count >= 28) {
				middle.reset();
				count = outer.rotate();
				count = 0;
			}
			/**/
			//if (count >= 26) {
			//	inner.reset();
			//	count = middle.rotate();
			//	//count = 0;
			//}
			//if (count >= 28) {
			//	middle.reset();
			//	count = outer.rotate();
			//	count = 0;
			//}
			/**/
			/**/
			//if (count >= 28) {
			//	inner.reset();
			//	count = middle.rotate();
			//}
			//if (count >= 56) {
			//	middle.reset();
			//	count = outer.rotate();
			//	
			//}
			//if (count >= 84) {
			//	outer.reset();
			//	count = 0;
			//}
			/**/




			//if (count < 28) {
			//	inner.rotate();
			//	count++;
			//}
			//else if (count >= 28) {
			//	inner.reset();
			//	middle.rotate();
			//	count++;
			//}
			//else if (count >= 56) {
			//	middle.reset();
			//	outer.rotate();
			//	
			//}
			//else {
			//	count = 0;
			//}
		

		}

		if (lower) {
			decrypt = tolower(decrypt);
		}

		final += decrypt;
		//count = inner.rotate();
		//if (count >= 26) {
		//inner.reset();
		//count = middle.rotate();
		//}
		//if (count >= 28) {
		//middle.reset();
		//count = outer.rotate();
		//count = 0;
		//}
		encodedMessage.push_back(decrypt);

		myFile << decrypt;
	}

	cout << endl << "Message before encryption/decryption: " << message << endl;
	cout << endl << "Message after encryption/decryption: " << final << endl;
}

/* Sets message */
void Coder::setMessage(string message) {
	message = message;
}

/* Gets message */
string Coder::getMessage() {
	return message;
}

/* Prints message */
void Coder::printMessage() {
	cout << message;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

/* Wheels foward position */
char Coder::wheelsForwardWithoutSteps(char original) {
	int position;
	char converted;
	//cout << original;

	/* Inner Rotor */
	position = inner.getIndex(original);
	// cout << " -> " << position;


	/* Outer Rotor */
	converted = outer.getCharacter(position);
	// cout << " -> " << converted;

	/* Middle Rotor */
	position = middle.getIndex(converted);
	// cout << " -> " << position;

	/* Outer Rotor */
	converted = outer.getCharacter(position);
	// cout << " -> " << converted;


	//cout << endl << endl;
	return converted;

}

/* Wheels reverse position */
char Coder::wheelsReverseWithoutSteps(char original) {
	int position;
	char converted;

	//cout << original;

	/* Outer Rotor */
	position = outer.getIndex(original);
	// cout << " -> " << position;

	/* Middle Rotor */
	converted = middle.getCharacter(position);
	// cout << " -> " << converted;

	/* Outer Rotor */
	position = outer.getIndex(converted);
	// cout << " -> " << position;

	/* Inner Rotor */
	converted = inner.getCharacter(position);
	// cout << " -> " << converted;

	// cout << endl << endl;
	return converted;

}

void Coder::runMachineWithoutSteps() {
	int index;
	int count = 0;
	char decrypt;
	bool lower = false;
	string beforePlug;
	string temp;
	string final;

	for (int i = 0; i < message.size(); i++) {
		temp += toupper(message[i]);
	}
	message = temp;
	cout << endl << "The message is: " << message;

	/* take the message and input into a vector */
	vector <char> lettersInput(message.begin(), message.end());

	/* print vector out */
	for (int i = 0; i < lettersInput.size(); i++) {
		/* just to make sure the code inputted is correct*/
		//cout << lettersInput[i];
	}



	for (auto letter : lettersInput) {

		/* take the char and plug it into the plugboard */
		decrypt = plugboard.usePlugWithoutSteps(letter); // plugs the character into the plugboard

		/* lower the output character */
		//inner = islower(decrypt); // makes the letter lowercase

		if (islower(decrypt)) {
			decrypt = toupper(decrypt);
		}

		if (isalpha(decrypt) || decrypt == ' ' || decrypt == '.') {

			/* wheels foward*/
			decrypt = wheelsForwardWithoutSteps(decrypt);

			/* reflector */
			decrypt = reflector.useReflectorWithoutSteps(decrypt);

			/* wheels reverse */
			decrypt = wheelsReverseWithoutSteps(decrypt);

			/* plugboard again */
			decrypt = plugboard.usePlugWithoutSteps(decrypt); // plugs the character into the plugboard
			//cout << endl << decrypt << endl;
			

			count = inner.rotate();
			if (count >= 26) {
				inner.reset();
				middle.rotate();
				count = 0;
			}
			if (count >= 28) {
				middle.reset();
				outer.rotate();
				count = 0;
			}



		}

		if (lower) {
			decrypt = tolower(decrypt);
		}

		final += decrypt;

		encodedMessage.push_back(decrypt);

		myFile << decrypt;

	}
	cout << endl << endl << endl;
	cout << endl << "Message before encryption/decryption: " << message << endl;
	cout << endl << "Message after encryption/decryption: " << final << endl;

	/* ADD WHERE IT SAVES THE FINAL VARIABLE TO THE OUTPUT FILE */
}
