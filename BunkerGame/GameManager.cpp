#include "FileParser.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>
#include "TextPrints.h"
#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

bool GameManager::LoadBunkerDataIntoJSONVector(string fileName)
{
	if (fp.AddDataToJSONFile(fp.ParseFileFromJSON(fileName))) {
		tp.PrintDebug("Raw JSON data added to JSON vector");
		return true;
	}
	else {
		cout << "Error adding raw JSON data to JSON vector" << endl;
		return false;
	}
}

void GameManager::setDebug()
{
	string input;

	cout << "Enable debug prints?" << endl;
	getline(cin, input);

	while (!iv.IsValidYesNo(input[0])) {
		cout << "Enable debug prints?" << endl;
		getline(cin, input);
	}
	if (input[0] == 'y' || input[0] == 'Y') {
		tp.EnableDebug(true);
	}
	else if (input[0] == 'n' || input[0] == 'N') {
		tp.EnableDebug(false);
	}
}
