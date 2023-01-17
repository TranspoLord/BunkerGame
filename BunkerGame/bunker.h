#pragma once
#include <map>
#include <string>
#include "room.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;

class bunker
{
public:
	bunker();
	~bunker();
	
	bool SetRoomData(string index, json data);
	vector<string> GetRoomData(string index);

private:
	
	int bunkerID;
	int numOfRooms;
	map<string, room> roomData;
	
};


