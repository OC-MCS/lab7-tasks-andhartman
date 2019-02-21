#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RetailItem
{
private:
	string description;
	int unitsOnHand;
	double price;
public:
	RetailItem(string = " ", int = 0, double = 0);
	void loaditems(vector<RetailItem>&);
	string getDescription();
	int getStock();
	double getPrice();
	double getStockValue();
};