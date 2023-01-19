#include "room.h"
#include <iostream>

room::room()
{
}

room::~room()
{
}

bool room::SetRoomJSONData(json data) {
	rawJSONdata = data;
	if (rawJSONdata.empty()) {
		return false;
	}
	else {
		return true;
	}
}

json room::GetRawJSONData() {
	return rawJSONdata;
}

void room::SetDebug(bool condition) {
	debug = condition;
}

void room::DebugPrint(string text) {
	if (debug) {
		cout << "ROOM DEBUG: " + text << endl;
	}
}

json& room::GetRoomRawJSONData() {
	return rawJSONdata;
}

bool room::BuildRoom(int ID) {
	DebugPrint("Building room " + to_string(ID) + " with data : " + rawJSONdata.dump() + "\n\n");

	roomDetails["Name"] = rawJSONdata["Name"].dump();
	roomDetails["Desc"] = rawJSONdata["Room Description"].dump();
	roomDetails["Item"] = rawJSONdata["Item"].dump();
	roomDetails["PickupWords"] = rawJSONdata["Accepted Pickups"].dump();
	roomDetails["North"] = rawJSONdata["North"].dump();
	roomDetails["South"] = rawJSONdata["South"].dump();
	roomDetails["East"] = rawJSONdata["East"].dump();
	roomDetails["West"] = rawJSONdata["West"].dump();
	
	roomID = ID;
	if(rawJSONdata["Bacon Item?"].dump() == "N")
		baconItem = false;
	else
		baconItem = true;

	DebugPrint("Room " + to_string(roomID) + " data set \n");
	for (auto& x : roomDetails) {
		if (roomDetails.at(x.first).empty()) {
			return false;
		}
		DebugPrint(x.first + ": " + x.second);
	}
	return true;
}