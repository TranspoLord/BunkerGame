#include "bunker.h"
#include <iostream>

bunker::bunker() {
	bunkerID = 0;
	numOfRooms = 0;
	debug = false;
}

bunker::~bunker()
{
}

void bunker::SetDebug(bool condition) {
	debug = condition;
}

void bunker::DebugPrint(string text) {
	if (debug) {
		cout << "BUNKER DEBUG: " + text << endl;
	}
}


bool bunker::SetRawJSONData(json data, int ID) {
	rawBunkerData = data;
	if (rawBunkerData.empty()) {
		DebugPrint("Error setting raw bunker data");
		return false;
	}
	else {
		bunkerID = ID;
		numOfRooms = data["NumberOfRooms"];
		bunkerName = rawBunkerData["Bunker Name"];
		for (int i = 0; i < numOfRooms; i++) {
			DebugPrint("Trying to load JSON into room: Room" + to_string(i + 1));
			rooms[i].SetRoomJSONData(rawBunkerData["Room" + to_string(i + 1)]);
			rooms[i].SetDebug(debug);
		}
		return true;
	}
}

json& bunker::GetRawJSONData() {
	return rawBunkerData;
}

vector<json> bunker::ReturnRoomRawJSONData() {
	vector<json> tempVector;
	for (int i = 0; i < numOfRooms; i++) {
		tempVector.push_back(rooms[i].GetRawJSONData());
	}
	return tempVector;
}

bool bunker::BuildRoomData() {
	for (int i = 0; i < numOfRooms; i++) {
		if(rooms[i].BuildRoom(i))
			DebugPrint("Room " + to_string(i) + " built successfully \n\n");
		else {
			DebugPrint("Error building room " + to_string(i));
			return false;
		}
	}
	return true;
}


