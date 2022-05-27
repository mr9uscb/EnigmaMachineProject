#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Wheel
{
private:
	string Rotor1 = "AUNGHOVBIPWCJQXDKRY ELSZFMT.";
	string Rotor2 = "O J.ETYCHMRWAFKPUZDINSXBGLQV";
	string Rotor3 = "FBDHJLNPRTVXZ.ACEGI KMOQSUWY";
	string Rotor4 = ".HKPDEAC WTVQMYNLXSURZOJFBGI";
	string Rotor5 = "YDNGLCIQVEZRPTAOXWBMJSUH.K F";

	string finalOutput;
	string t1;
	int wheel;
	int counter;

public:
	Wheel();
	void reset();
	void setCode(int wheel);
	int rotate();
	int getIndex(char original);
	char getCharacter(int position);
	void startPosition();
	string getCode();
	string code;
};



