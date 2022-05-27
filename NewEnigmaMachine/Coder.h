#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Wheel.h"
#include "Plugboard.h"
#include "Reflector.h"

class Coder
{
private:
	Plugboard plugboard;
	Reflector reflector;
	Wheel inner, middle, outer;
	Wheel wheel;

	vector <char> lettersInput;
	vector <char> encodedMessage;

	string output;
	string newMessage;
	string stringIn;
	string message;

	int rotateCounter = 0;
	int choice;

	string inFile = "data.txt";
	string outFile = "plugboardResult.txt";
	ifstream codeFile;
	ofstream encryptFile;
	ofstream myFile;

public:
	Coder();

	/* open and close the files */
	void openFile();			
	void openOutputFile();
	void closeFile();
	void closeOutputFile();

	/* Prompts and sets the plugboard settings */
	void getPlugboardSettings(); 

	/* Prompts and sets the reflector settings */
	void getReflectorSettings();

	/* Sets the wheels in the foward or reversed position */
	char wheelsForward(char original);
	char wheelsReverse(char original);

	/* Sets the message to the variable */
	void setMessage(string message);  

	/* Prompts and sets the wheels */
	void getWheels();

	/* Runs the enigma machine */
	void runMachine();

	/* Runs the enigma machine without showing steps so that the output is cleaner */
	void runMachineWithoutSteps();

	string getMessage();  
	void printMessage();
	void promptUser();

	char wheelsForwardWithoutSteps(char original);
	char wheelsReverseWithoutSteps(char original);

};

