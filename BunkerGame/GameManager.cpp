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

void GameManager::MigrateBunkerJSONData(const json &data) {
	bunker tempBunker;
	tempBunker.SetRawJSONData(data);
	bunkers[numOfBunkers] = tempBunker;
	DebugPrint(bunkers[numOfBunkers].GetRawJSONData().dump());
	numOfBunkers++;
}

void GameManager::LoadBunkerData(string fileName)
{
	MigrateBunkerJSONData(fp.ParseFileToJSON(fileName));
}

