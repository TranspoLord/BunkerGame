#include "FileParser.h"

FileParser::FileParser() {
	debug = false;
}

FileParser::~FileParser() {
}

void FileParser::SetDebug(bool debug) {
	this->debug = debug;

}

void FileParser::DebugPrint(string text) {
	if (debug) {
		cout << "FILE PARSER DEBUG: " + text << endl;
	}
}

bool FileParser::ValidateFile(string fileName) {
	ifstream file(fileName);
	if (file.is_open()) {
		DebugPrint("File found");
		return true;
	}
	else {
		DebugPrint("File not found");
		return false;
	}
}

json FileParser::ParseFileToJSON(string fileName) {
	json temp;
	ifstream file(fileName);
	if (file.is_open()) {
		DebugPrint("File opened");
		temp = json::parse(file);
		file.close();
	}
	else {
		DebugPrint("Error opening file");
	}
	return temp;
}







