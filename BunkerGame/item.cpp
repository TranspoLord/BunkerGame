#include "item.h"
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

item::item()
{
}

item::~item()
{
} 

void item::SetDebug(bool condition) {
	debug = condition;
}

void item::DebugPrint(string text) {
	if (debug) {
		cout << "ITEM DEBUG: " + text << endl;
	}
}

void item::SetID(int id) {
	itemID = id;
}

int item::GetID() {
	return itemID;
}

string item::GetName() {
	return name;
}

void item::SetName(string name) {
	this->name = name;
}

string item::GetDescription() {
	return description;
}

void item::SetDescription(string description) {
	this->description = description;
}

string item::GetAcceptedPickupKeywords() {
	return acceptedPickupKeywords;
}

void item::SetAcceptedPickupKeywords(string keywords) {
	acceptedPickupKeywords = keywords;
}

string item::GetItemNeededToGet() {
	return itemNeeded;
}

void item::SetItemNeededToGet(string itemNeeded) {
	this->itemNeeded = itemNeeded;
}

string item::GetItemAlreadyAcquired() {
	return itemAlreadyAquired;
}

void item::SetItemAlreadyAcquired(string itemAcquired) {
	itemAlreadyAquired = itemAcquired;
}

bool item::GetItemBacon() {
	return bacon;
}

void item::SetItemBacon(string itemBacon) {
	if (itemBacon == "Y" || itemBacon == "y") {
		bacon = true;
	}
	else {
		bacon = false;
	}
}

string item::GetPickupDesc() {
	return itemPickup;
}

void item::SetPickupDesc(string pickupDesc) {
	itemPickup = pickupDesc;
}


