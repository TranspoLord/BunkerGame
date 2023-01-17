#include "FileParser.h"

FileParser::FileParser() {
	debug = false;
}

FileParser::~FileParser() {
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

vector<string> FileParser::SeperateString(string line, char delimiter) {
	vector<string> vOfStrings;
	stringstream ss(line);
	string token;
	while (getline(ss, token, delimiter)) {
		vOfStrings.push_back(token);
	}
	return vOfStrings;
}

void FileParser::SetDebug(bool debug) {
	this->debug = debug;
	
}

json FileParser::ParseFileFromJSON(string fileName) {
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

bool FileParser::AddDataToJSONVector(json data) {
	bunkersRawJSONData.push_back(data);
	return true;
}

int FileParser::GetNumOfRoomsInBunker(int bunkerIndex) {
	return bunkersRawJSONData[bunkerIndex]["NumberOfRooms"];
}

json FileParser::GetBunkerRoomData(int bunkerIndex, int roomIndex) {
	if (bunkerIndex <= bunkersRawJSONData.size())
	{
		if (roomIndex <= GetNumOfRoomsInBunker(bunkerIndex))
		{
			
			DebugPrint("Trying to get room data from room " + to_string(roomIndex) + " at bunker " + to_string(bunkerIndex) + "\n");
			DebugPrint("This is the raw room data");
			DebugPrint("Room data: " + bunkersRawJSONData[bunkerIndex]["Room"+to_string(roomIndex)].dump());
			return bunkersRawJSONData[bunkerIndex]["Room" + roomIndex];
		}
		else {
			DebugPrint("Room index out of range");
			return NULL;
		}
	}
	else {
		DebugPrint("Bunker index out of range");
		return NULL;
	}

} 

void FileParser::DebugPrint(string text) {
	if (debug) {
		cout << text << endl;
	}
}





