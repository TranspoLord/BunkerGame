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
	
	bool SetRawJSONData(json data);
	json& GetRawJSONData();

private:
	
	int bunkerID;
	string bunkerName;
	int numOfRooms;
	json rawBunkerData;
	
};


