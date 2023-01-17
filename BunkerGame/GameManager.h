#pragma once
#include <fstream>
#include "nlohmann/json.hpp"
#include "InputValidation.h"
using json = nlohmann::json;

using namespace std;

class GameManager
{
public:
	
	GameManager();
	~GameManager();
	
	FileParser fp;
	
	void setDebug();
	bool LoadBunkerDataIntoJSONVector(string fileName);
	
private: 
	
	
	TextPrints tp;
	InputValidation iv;
	
};

