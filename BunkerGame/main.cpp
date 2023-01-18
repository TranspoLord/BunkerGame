#include <iostream>
#include <string>
#include "InputValidation.h"
#include "FileParser.h"
#include "GameManager.h"

using namespace std;

string TestBunkerFile = "Test.json";
GameManager gameManager;

void AskDebug();

int main(int argc, char){

	AskDebug();
	gameManager.LoadBunkerData(TestBunkerFile);
	gameManager.PrintRawRoomJSONDataFromBunker(0);
	
	return 0;
};

void AskDebug() {
	string input;

	cout << "Enable debug prints?" << endl;
	getline(cin, input);

	while (!gameManager.iv.IsValidYesNo(input[0])) {
		cout << "Enable debug prints?" << endl;
		getline(cin, input);
	}
	if (input[0] == 'y' || input[0] == 'Y') {
		gameManager.SetDebug(true);
	}
	else if (input[0] == 'n' || input[0] == 'N') {
		gameManager.SetDebug(false);
	}
}





