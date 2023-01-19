#include <iostream>
#include "InputValidation.h"
#include <string>


InputValidation::InputValidation() {
}

InputValidation::~InputValidation() {
}

bool InputValidation::IsValidAlphaString(string input) {
	for (char c : input) {
		if (!isalpha(c)) {
			cout << error;
			return false;
		}
	}
	return true;
}


bool InputValidation::IsValidAlphaSingle(char input) {
	if (isalpha(input)) {
		return true;
	}
	cout << "Not an Alpha Character" << endl;
	return false;
}

bool InputValidation::IsValidYesNo(char input) {
	if (!IsValidAlphaSingle(input)) {
		return false;
	}
	else if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
		cout << "Not an acceptable input" << endl;
		return false;
	}
	return true;
}

bool InputValidation::IsValidNumber(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			cout << error;
			return false;
		}
	}
	return true;
}

bool InputValidation::IsValidPickup(string input, string textFile) {
	if (!IsValidAlphaString(input)) cout << error; return false;


	return true;
}
