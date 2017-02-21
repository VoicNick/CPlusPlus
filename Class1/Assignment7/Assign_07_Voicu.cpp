// Assignment 7 COMP 2617
// This is the solution for the Ex 8.12 as required
// for the Assignment 7
// The program simulates a race between a hare and a tortoise
// given an set of possible moves over a fixed lenght corse
//
// Author:	Voicu Chirtes
// Date:	Mar 23, 2015


#include <array>
#include <iostream>
#include <ctime>
#include <random>


using namespace std;

//contestant identifiers
const static char hareId = 'H';
const static char tortoiseId = 'T';

//start and finish position values on the track
const static int START_POSITION = 1;
const static int END_POSITION = 70;

//display track at any given time
void showTrack(const unsigned int &harePos, const unsigned int &tortoisePos);


int main()
{
	// possible moves an contestant can do. In initial version
	// they are limited to 10 each move has a 10% chance of happening
	const int POSSIBLE_MOVES = 10;

	// The arrays will store the possible moves for each contestant
	// according to their probability of happening.
	// Array values are used to represent the possible move values: 0=no move, 
	// positive = move to right/forward, negative = move to left/backwards
	// indexes represent the probability of a move;  1 index = 10%
	const array<int, POSSIBLE_MOVES> hareMoves = { 0, 0, 9, 9, -12, 1, 1, 1, -2, -2 };
	const array<int, POSSIBLE_MOVES> tortoiseMoves = { 3, 3, 3, 3, 3, -6, -6, 1, 1, 1 };

	// random numbers generation objects
	default_random_engine engine(static_cast <unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(0,9);

	// variables to store the position of each contestant on the track
	int harePosition = START_POSITION;
	int tortoisePosition = START_POSITION;
	
	// variable ot store number of "seconds" elapsed since start
	// NOTE: these are not reat time secounds but loop cycles
	int secounds = 0;

	cout << "ON YOUR MARK, GET SET" << endl;
	cout << "BANG               !!!!" << endl;
	cout << "AND THEY'RE OFF    !!!!" << endl;

	while (harePosition < END_POSITION 
		&& tortoisePosition< END_POSITION)
	{
		secounds++;
		harePosition += hareMoves[randomInt(engine)]; 
		if (harePosition < START_POSITION)
		{
			harePosition = START_POSITION;
		}

		tortoisePosition += tortoiseMoves[randomInt(engine)];
		if (tortoisePosition < START_POSITION)
		{
			tortoisePosition = START_POSITION;
		}

		if ((harePosition < END_POSITION
			&& tortoisePosition < END_POSITION))
		{
			showTrack(harePosition, tortoisePosition);
		}
		else
		{
			cout << endl;
		}
	}

	//race done, let's show the winner and time
	if ((harePosition >= END_POSITION) && 
		(tortoisePosition >= END_POSITION))
	{
		cout << "It's a tie." << endl;
	}
	else
	{
		if (tortoisePosition >= END_POSITION)
		{
			cout << "TORTOISE WINS!!! YAY!!!\n" << endl;
		}
		else
		{
			cout << "Hare wins. Yuch.\n" << endl;
		}
	}

	cout << "TIME ELAPSED = " << secounds <<" seconds\n" << endl;

	return 0;
}


//display track at any given time
void showTrack(const unsigned int &harePos, const unsigned int &tortoisePos)
{

	for (int i = 0; i < END_POSITION; i++)
	{
		if (i == harePos)
		{
			if (i == tortoisePos)
			{
				cout << "OUCH!!!";
			}
			else
			{
				cout << hareId;
			}
		}
		else
		{
			if (i == tortoisePos)
			{
				cout << tortoiseId;
			}
			else
			{
				cout << " ";
			}
		}
	}
	cout << endl;
}

