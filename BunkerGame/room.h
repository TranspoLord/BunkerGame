#pragma once
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;



class room
{
public:

	room();
	~room();

	bool SetRoomJSONData(json data);
	json GetRawJSONData();
	json& GetRoomRawJSONData();
	
	

private:
	
	string roomID;
	string name;
	string description;
	string firstTimeEnter;
	string itemName;
	bool baconItem;
	string acceptedPickupKeywords;
	string north;
	string south;
	string east;
	string west;
	json rawJSONdata;
	
};

