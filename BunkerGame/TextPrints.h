#pragma once
#include <string>
#include <iostream>
using namespace std;

class TextPrints {
	
public:
	
	TextPrints();
	~TextPrints();
	
	void EnableDebug(bool choice);
	void PrintDebug(string input);
	void PrintLine(string input);

private:
	bool debugEnabled = false;
};


