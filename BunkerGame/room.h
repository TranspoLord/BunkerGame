#pragma once
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "item.h"
using json = nlohmann::json;

using namespace std;



class room
{
public:

	room();
	~room();

	void SetDebug(bool condition);
	void DebugPrint(string text);

	bool SetRoomJSONData(json data);
	json GetRawJSONData();
	json& GetRoomRawJSONData();
	bool BuildRoom(int ID);
	bool CreateItem(json &data);
	

private:
	
	json rawJSONdata;
	
	bool debug;
	
	bool baconItem;
	int roomID;
	int itemsInRoom = 0;
	
	map<string, string> roomDetails;
	
	vector<item> roomItems;

	string name;
	string description;
	string itemName;
	string acceptedPickupKeywords;
	string north;
	string south;
	string east;
	string west;
	
	
};

