#pragma once
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;



class room
{
public:

private:
	
	string roomID;
	string name;
	string description;
	
	string firstTimeEnter;
	
	string itemID;
	
	
	string north;
	string south;
	string east;
	string west;
	
};

