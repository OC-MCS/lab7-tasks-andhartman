#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "RetailItem.h"

int main()
{
	vector<RetailItem> b;
	RetailItem a;
	a.loaditems(b);

	cout << setw(15) << "Description" << setw(10) << "Price" << setw(10) << "On Hand" << setw(10) << "Value" << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < b.size(); i++)
	{
		cout << left << setw(16) << b[i].getDescription() << setw(10) << right << b[i].getPrice() << setw(10) << b[i].getStock() << setw(10) << b[i].getStockValue() << endl;
	}

	return 0;
}