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
	fp = FileParser();
	iv = InputValidation();
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
	cout << "\n\n****Bunker Created****\n";
	cout << " Bunker ID: " << tempBunker.GetBunkerID() << endl;
	cout << " Bunker Name: " << tempBunker.GetBunkerName() << endl;
	cout << " Number of Rooms: " << tempBunker.GetNumOfRooms() << endl;
	cout << "****Bunker Created****\n\n";
}

void GameManager::PrintRawRoomJSONDataFromBunker(int index)
{
	vector<json> temp = bunkers[index].ReturnRoomRawJSONData();
	for (int i = 0; i < temp.size(); i++) {
		DebugPrint("Room: " + to_string(i+1) + "\n \n" + temp[i].dump() + "\n \n");
	}
}

void GameManager::AskCreateBunkerFromFile() {
	string fileName;
	bool fileFound = false;
	do {
		cout << "Enter the name of the file you want to load, or" << endl;
		cout << "type 'Default' to load default: ";
		getline(cin, fileName);
		if (fileName == "Default" || fileName == "default") {
			fileName = "Test.json";
			fileFound = true;
		}
		if(FileParser().ValidateFile(fileName))
			fileFound = true;
		else
			cout << "File not found, please try again" << endl;
	} while (!fileFound);
	LoadBunkerData(fileName);
}

void GameManager::SelectBunkerInt()
{
	string temp;
	bool valid = false;
	do {
		cout << "Enter the ID of the bunker you want to select, or 'return' to go back: ";
		getline(cin, temp);
		if (temp == "return" || temp == "Return") {
			return;
		}
		else if (iv.IsValidNumber(temp)) {
			int index = stoi(temp);
			if (index < numOfBunkers) {
				valid = true;
				selectedBunker = index;
			}
			else {
				cout << "Bunker not found, or wrong index, please try again" << endl;
			}
		}
		else {
			cout << "Invalid input, please try again" << endl;
		}
	} while (!valid);
}

void GameManager::MainMenu() {
	string input;
	bool valid = false;
	do {
		cout << " Welcome to the Bunker Game" << endl;
		cout << " Please select an option:" << endl;
		cout << " 1. Create a new bunker from file" << endl;
		cout << " 2. Select a bunker" << endl;
		cout << " 3. Set debuging prints" << endl;
		cout << " 4. Exit" << endl;
		getline(cin, input);
		if (iv.IsValidNumber(input)) {
			int choice = stoi(input);
			switch (choice) {
			case 1:
				AskCreateBunkerFromFile();
				break;
			case 2:
				SelectBunkerInt();
				break;
			case 3:
				cout << endl;
				SetDebug(!debug);
				cout << endl;
				break;
			case 4:
				valid = true;
				break;
			default:
				cout << "Invalid input, please try again" << endl;
				break;
			}
		}
		else {
			cout << "Invalid input, please try again" << endl;
		}
	} while (!valid);
}





