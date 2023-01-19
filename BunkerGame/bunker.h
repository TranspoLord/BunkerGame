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

	void SetDebug(bool condition);
	void DebugPrint(string text);
	
	bool SetRawJSONData(json data, int ID);
	json& GetRawJSONData();
	vector<json> ReturnRoomRawJSONData();
	bool BuildRoomData();
	int GetBunkerID();
	string GetBunkerName();
	int GetNumOfRooms();


private:
	
	bool debug;
	int bunkerID;
	string bunkerName;
	int numOfRooms;
	json rawBunkerData;
	map<int, room> rooms;
	
};


