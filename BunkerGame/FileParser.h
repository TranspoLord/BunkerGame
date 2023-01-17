#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;



class FileParser {
	
public:
	FileParser();
	~FileParser();
	
	void SetDebug(bool debug);
	void DebugPrint(string text);

	bool ValidateFile(string fileName);
	vector<string> SeperateString(string line, char delimiter);
	json ParseFileFromJSON(string fileName);
	bool AddDataToJSONVector(json data);
	int GetNumOfRoomsInBunker(int index);
	json GetBunkerRoomData(int bunkerIndex, int roomIndex);
	
	//TODO: create function that gets json data from vector and prevents out of index errors
	//TODO: add a way to get the number of rooms per bunker
	//TODO: Assign an ID to each bunker
	

private:
	
	bool debug = false;
	
	//TODO: Change to map
	vector<json> bunkersRawJSONData;
	
};

