#include "room.h"
#include <iostream>

room::room()
{
}

room::~room()
{
}

room room::SetRoomData(json data)
{
	//roomID = data["roomID"];
	name = data["Name"];
	description = data["Room Description"];
	//firstTimeEnter = data["firstTimeEnter"];
	//itemID = data["itemID"];
	north = data["North"];
	south = data["South"];
	east = data["East"];
	west = data["West"];
	itemName = data["Item"];
	baconItem = data["Bacon Item?"];
	acceptedPickupKeywords = data["Accepted Pickups"];
	return *this;
}

vector<string> room::GetRoomData()
{
	cout << "In get room data" << endl;
	vector<string> temp;
	temp.push_back(name);
	temp.push_back(description);
	temp.push_back(north);
	temp.push_back(south);
	temp.push_back(east);
	temp.push_back(west);
	temp.push_back(itemName);
	temp.push_back(to_string(baconItem));
	temp.push_back(acceptedPickupKeywords);
	return temp;
}
