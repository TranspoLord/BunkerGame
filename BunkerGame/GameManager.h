#pragma once
#include <fstream>
#include "nlohmann/json.hpp"
#include "InputValidation.h"
#include "bunker.h"
using json = nlohmann::json;

using namespace std;

class GameManager
{
public:
	
	GameManager();
	~GameManager();
	InputValidation iv;
	FileParser fp;
	
	void DebugPrint(string text);
	void SetDebug(bool set);

	void LoadBunkerData(string fileName);
	void MigrateBunkerJSONData(const json& data);
	void PrintRawRoomJSONDataFromBunker(int index);
	
	
private:
	
	bool debug = false;
	map<int, bunker> bunkers;
	int numOfBunkers = 0;
	
	
	
};

