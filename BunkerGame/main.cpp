#include <iostream>
#include <string>
#include "InputValidation.h"
#include "FileParser.h"
#include "GameManager.h"

using namespace std;

string TestBunkerFile = "Test.json";

InputValidation validation;
GameManager gameManager;


int main(int argc, char){

	gameManager.EnableDebug();
	gameManager.LoadBunkerDataIntoJSONVector(TestBunkerFile);
	cout << "Number of rooms in bunker 0: " << gameManager.fp.GetNumOfRoomsInBunker(0) << endl;
	
	cout << gameManager.fp.GetBunkerRoomData(0, 1);
	
	gameManager.PrintRoomData(0, "1");
	
	
	return 0;
};





