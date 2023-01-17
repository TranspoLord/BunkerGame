#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "TextPrints.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;



class FileParser {
	
public:
	FileParser();
	~FileParser();
	
	void setDebug(bool debug);

	bool ValidateFile(string fileName);
	vector<string> SeperateString(string line, char delimiter);
	json ParseFileFromJSON(string fileName);
	bool AddDataToJSONFile(json data);
	int GetNumOfRoomsInBunker(int index);
	//TODO: create function that gets json data from vector and prevents out of index errors
	//TODO: add a way to get the number of rooms per bunker
	//TODO: Assign an ID to each bunker
	

private:
	
	TextPrints tpPrint;
	
	vector<string> errorStrings;	
	vector<json> bunkersRawJSONData;
};

