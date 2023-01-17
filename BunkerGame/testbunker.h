#pragma once
#include <string>
#include <iostream>
#include <string>

using namespace std;

class testbunker {
public:
	
	string name = "Hallway";
	string description = "You are in the entrance of the bunker. It has a small desk and a check in area.\n";
	string pickupWords = "Pickup Computer Battery";
	string item = "";
	int itemID = 0;
	string itemPickupDesc = "You've picked up a computer battery";
	string itemAlreadyAquired = "There's ntohing else here to pickup";
	string itemNeeded = "";
	string northRoomName = "Side Storage";
	int northRoomID = 1;
	string southRoomName = "Large Hall";
	int southRoomID = 3;
	string eastRoomName = "Food Storage";
	int eastRoomID = 2;
	string westRoomName = "Entrance";
	int westRoomID = 0;
	
};