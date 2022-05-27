#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Plugboard
{
private:
	string plugboardSettingString;
	string part1, part2; 
	string plugboardSetting; 
	int counter = 0; 

public:
	Plugboard();
	void promptUser();
	void splitCharacterString();
	char usePlug(char original);
	string getSplitCharacterString();

	char usePlugWithoutSteps(char original);
};

