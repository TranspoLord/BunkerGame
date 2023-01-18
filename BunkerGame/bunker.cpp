#include "bunker.h"

bunker::bunker() {
	bunkerID = 0;
	numOfRooms = 0;
	roomData = map<string, room>();
}

bunker::~bunker()
{
}

bool bunker::SetRoomData(string index, json data)
{
	roomData[index].SetRoomData(data);
	return true;
}

vector<string> bunker::GetRoomData(string index)
{
	vector<string> temp = roomData[index].GetRoomData();
	return temp;
}
