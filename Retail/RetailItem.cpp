#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "RetailItem.h"

void RetailItem::loaditems(vector<RetailItem> &a)
{
	string tmp;
	RetailItem temp;
	ifstream file;
	file.open("Book1.csv");

	while (getline(file, temp.description, ','))
	{
		getline(file, tmp, ',');
		temp.price = stod(tmp);
		getline(file, tmp, '\n');
		temp.unitsOnHand = stoi(tmp);
		a.push_back(temp);
	}

	file.close();
}

double RetailItem::getStockValue()
{
	double total;
	total = unitsOnHand * price;
	return total;
}

RetailItem::RetailItem(string a, int b, double c)
{
	description = a;
	unitsOnHand = b;
	price = c;
}

int RetailItem::getStock()
{
	return unitsOnHand;
}

double RetailItem::getPrice()
{
	return price;
}

string RetailItem::getDescription()
{
	return description;
}