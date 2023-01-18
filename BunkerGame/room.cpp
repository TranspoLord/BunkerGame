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
