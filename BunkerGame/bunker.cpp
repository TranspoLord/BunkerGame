#include "bunker.h"

bunker::bunker() {
	bunkerID = 0;
	numOfRooms = 0;
}

bunker::~bunker()
{
}

bool bunker::SetRawJSONData(json data) {
	rawBunkerData = data;
	if (rawBunkerData.empty()) {
		return false;
	}
	else {
		return true;
	}
}

json& bunker::GetRawJSONData() {
	return rawBunkerData;
}
