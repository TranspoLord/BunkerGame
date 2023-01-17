#include "FileParser.h"

FileParser::FileParser() {
}

FileParser::~FileParser() {
}

bool FileParser::ValidateFile(string fileName) {
	ifstream file(fileName);
	if (file.is_open()) {
		tpPrint.PrintDebug("File found");
		return true;
	}
	else {
		tpPrint.PrintDebug("File not found");
		return false;
	}
}

vector<string> FileParser::SeperateString(string line, char delimiter) {
	vector<string> vOfStrings;
	stringstream ss(line);
	string token;
	while (getline(ss, token, delimiter)) {
		vOfStrings.push_back(token);
	}
	return vOfStrings;
}

void FileParser::setDebug(bool debug) {
	tpPrint.EnableDebug(debug);
}

json FileParser::ParseFileFromJSON(string fileName) {
	json temp;
	ifstream file(fileName);
	if (file.is_open()) {
		tpPrint.PrintDebug("File opened");
		temp = json::parse(file);
		file.close();
	}
	else {
		tpPrint.PrintDebug("Error opening file");
	}
	return temp;
}

bool FileParser::AddDataToJSONFile(json data) {
	bunkersRawJSONData.push_back(data);
	return true;
}

int FileParser::GetNumOfRoomsInBunker(int index) {
	return bunkersRawJSONData[index]["NumberOfRooms"];
}





