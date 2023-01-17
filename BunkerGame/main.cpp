#include <iostream>
#include <string>
#include "InputValidation.h"
#include "TextPrints.h"
#include "FileParser.h"
#include "GameManager.h"

using namespace std;

string TestBunkerFile = "Test.json";

InputValidation validation;
GameManager gameManager;


int main(int argc, char){

	gameManager.setDebug();
	gameManager.LoadBunkerDataIntoJSONVector(TestBunkerFile);
	cout << gameManager.fp.GetNumOfRoomsInBunker(0);
	
	return 0;
};





