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
	
	FileParser fp;
	
	void DebugPrint(string text);
	void EnableDebug();
	
	bool LoadBunkerDataIntoJSONVector(string fileName);
	bool LoadRoomDataIntoRooms(int bunkerIndex);
	void SetCurrentBunker(int index);
	bunker GetCurrentBunker();
	void PrintRoomData(int bunkerIndex, string roomIndex);
	
private: 
	
	bool debug = false;
	InputValidation iv;

	//TODO: Start changing vectors to maps
	vector<bunker> bunkers;
	int currentBunker;
	
};

