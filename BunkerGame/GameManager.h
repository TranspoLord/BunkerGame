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
	void PrintRawRoomJSONDataFromBunker(int index);

	//void PrintBunkerData(int index);

	void AskCreateBunkerFromFile();
	void SelectBunkerInt();
	//void SelectBunkerString(string name);
	void MainMenu();
	//TODO: Create a function that tests if a bunker has been created already
	
	
private:
	
	bool debug = false;
	map<int, bunker> bunkers;
	int numOfBunkers = 0;
	int selectedBunker = 0;
	vector<string> bunkerFileNames;
	
	
};

