#include "FileParser.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	debug = false;
}

GameManager::~GameManager()
{
}

void GameManager::DebugPrint(string text)
{
	if (debug) {
		cout << "GAME MANAGER DEBUG: " + text << endl;
	}
}

void GameManager::SetDebug(bool set)
{
	debug = set;
	fp.SetDebug(set);
	cout << "Debug set to " << debug << endl;
}


void GameManager::LoadBunkerData(string fileName)
{
	json data = fp.ParseFileToJSON(fileName);
	bunker tempBunker;
	if (debug)
		tempBunker.SetDebug(true);

	if (tempBunker.SetRawJSONData(data, numOfBunkers)) {
		DebugPrint("Bunker data succussfully migrated");
	}
	else {
		DebugPrint("Error migrating bunker data");
	}
	
	if (tempBunker.BuildRoomData()) {
		DebugPrint("Bunker data succussfully built!");
	}
	else {
		DebugPrint("Error building bunker data");
	}

	bunkers[numOfBunkers] = tempBunker;
	numOfBunkers++;
	
}

void GameManager::PrintRawRoomJSONDataFromBunker(int index)
{
	vector<json> temp = bunkers[index].ReturnRoomRawJSONData();
	for (int i = 0; i < temp.size(); i++) {
		DebugPrint("Room: " + to_string(i+1) + "\n \n" + temp[i].dump() + "\n \n");
	}
}

