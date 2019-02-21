#include <iostream>
#include <iomanip>
using namespace std;
#include "Die.h"

void displayPct(int*, int);

int main()
{
	int counter[7] = { 0,0,0,0,0,0,0 },
		counter2[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	Die six(6), twelve(12);

	counter[0] = 0;
	counter2[0] = 0;

	for (int i = 0; i < 1000000; i++)
	{
		six.roll();
		twelve.roll();
		counter[six.getValue()] += 1;
		counter2[twelve.getValue()] += 1;
		counter[0] += 1;
		counter2[0] += 1;
	}

	displayPct(counter, six.getSides());
	displayPct(counter2, twelve.getSides());

	return 0;
}

void displayPct(int* counter, int sides)
{
	cout << "Stats for " << sides << " sided die:" << endl;

	for (int i = 0; i < sides; i++)
	{
		cout << "Side " << setw(3) << i + 1 << ": " << fixed << setprecision(2) << (static_cast<float>(counter[i + 1]) / counter[0]) * 100 << "%" << endl;
	}
	cout << endl;
}