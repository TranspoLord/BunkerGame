#pragma once
#include <iostream>
#include <string>

using namespace std;

class item
{
public:
	 
	item();
	~item();

	void SetDebug(bool condition);
	void DebugPrint(string text);

	int GetID();
	void SetID(int id);
	
	string GetName();
	void SetName(string name);
	
	string GetDescription();
	void SetDescription(string description);
	
	string GetAcceptedPickupKeywords();
	void SetAcceptedPickupKeywords(string keywords);
	
	string GetItemNeededToGet();
	void SetItemNeededToGet(string itemNeeded);
	
	string GetItemAlreadyAcquired();
	void SetItemAlreadyAcquired(string itemAcquired);
	
	bool GetItemBacon();
	void SetItemBacon(string itemBacon);
	
	string GetPickupDesc();
	void SetPickupDesc(string pickupDesc);

private:
	
	bool debug;
	bool bacon;
	int itemID;
	
	string name;
	string description;
	string itemNeeded;
	string itemAlreadyAquired;
	string BaconItem;
	string acceptedPickupKeywords;
	string itemPickup;
};


