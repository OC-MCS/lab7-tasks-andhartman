#pragma once

// Specification file for the Die class


class Die
{
private:
	int sides;   // Number of sides
	int value;   // The die's value

public:
	Die(int);        // Constructor
	void roll();     // Rolls the die
	int getSides();  // Returns the number of sides
	int getValue();  // Returns the die's value
};
