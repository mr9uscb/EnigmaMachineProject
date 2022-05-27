#pragma once
#include <string>
#include <iostream>
using namespace std;

class Reflector
{
private:
	string output1 = "KM AX FZ GO DI CN BR PV LT EQ HS UW J. Y ";
	string output2 = "IU AS DV GL F. HT OX EZ CY J  MR KN BQ PW";
	string output3 = "AI BT MV HU FW EL DG KN YZ OQ CP SX J. R ";

	string reflectorSettings1 = "KMAXFZGODICNBRPVLTEQHSUWJ.Y ";
	string reflectorSettings2 = "IUASDVGLF.HTOXEZCYJ MRKNBQPW";
	string reflectorSettings3 = "AIBTMVHUFWELDGKNYZOQCPSXJ.R ";

	int choice;
	string part1, part2; 
	string reflectorSetting; 

public:
	Reflector(); 
	void promptUser();
	void splitCharacterString();
	string setReflector(int choice);
	void getReflector();
	char useReflector(char original);


	char useReflectorWithoutSteps(char original);
};

