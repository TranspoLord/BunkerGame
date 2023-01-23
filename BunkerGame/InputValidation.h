#pragma once
#include <string>
#include <cctype>
using namespace std;

class InputValidation {

public: 

	InputValidation();
	~InputValidation();

	bool IsValidAlphaString(string input);
	bool IsValidAlphaSingle(char input);
	bool IsValidYesNo(char input);
	bool IsValidNumber(string input);
	bool IsValidPickup(string input, string textFile);

private:
	string error = "Invalid input\n";
	
	
};
