#include "FileParser.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	bunkers = vector<bunker>();
	currentBunker = 0;
	debug = false;
}

GameManager::~GameManager()
{
}

bool GameManager::LoadBunkerDataIntoJSONVector(string fileName)
{
	if (fp.AddDataToJSONVector(fp.ParseFileFromJSON(fileName))) {
		DebugPrint("Raw JSON data added to JSON vector");
		return true;
	}
	else {
		cout << "Error adding raw JSON data to JSON vector" << endl;
		return false;
	}
}

void GameManager::EnableDebug()
{
	string input;

	cout << "Enable debug prints?" << endl;
	getline(cin, input);

	while (!iv.IsValidYesNo(input[0])) {
		cout << "Enable debug prints?" << endl;
		getline(cin, input);
	}
	if (input[0] == 'y' || input[0] == 'Y') {
		debug = true;
		fp.SetDebug(true);
	}
	else if (input[0] == 'n' || input[0] == 'N') {
		debug = false;
		fp.SetDebug(false);
	}
}

bool GameManager::LoadRoomDataIntoRooms(int bunkerIndex)
{
	int numOfRooms = fp.GetNumOfRoomsInBunker(bunkerIndex);
	for (int i = 0; i < numOfRooms; i++) {
		//TODO: Set room data
	}
	return true;
}

void GameManager::SetCurrentBunker(int index)
{
	currentBunker = index;
}

bunker GameManager::GetCurrentBunker()
{
	bunker bunker;
	bunker = bunkers[currentBunker];
	return bunker;
}

void GameManager::DebugPrint(string text)
{
	if (debug) {
		cout << text << endl;
	}
}

void GameManager::PrintRoomData(int bunkerIndex, string roomIndex){
	vector<string> temp = bunkers[bunkerIndex].GetRoomData(roomIndex);
	DebugPrint("Room data: ");
	for (int i = 0; i < temp.size(); i++) {
		DebugPrint(temp[i]);
	}
}

