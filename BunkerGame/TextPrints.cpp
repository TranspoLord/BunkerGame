#include "TextPrints.h"
#include <string>

using namespace std;

TextPrints::TextPrints() {
}

TextPrints::~TextPrints() {
}


void TextPrints::EnableDebug(bool choice) {
	if (choice) {
		cout << "Debug enabled" << endl;
		debugEnabled = true;
	}
	else {
		cout << "Debug disabled" << endl;
		debugEnabled = false;
	}
}

void TextPrints::PrintDebug(string input) {
	if (debugEnabled) {
		cout << input << endl;
	}
}

void TextPrints::PrintLine(string input) {
	cout << input << endl;
}