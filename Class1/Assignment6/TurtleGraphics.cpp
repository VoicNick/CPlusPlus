// Assignment 6 COMP 2617
// This is the implementation for the member functions of the 
// TurtleGraphics class as required in the Assignment 6 
// The TurtleGraphics.h  has the class definition
//
// Author:	Voicu Chirtes
// Date:	Mar 17, 2015

// include the class definition
#include "TurtleGraphics.h"

// include standard C libraries
#include <iostream>
#include <array>

using namespace std;

// ctor will init. floor to all "false" values, 
// as well as initialization of other data members
TurtleGraphics::TurtleGraphics(void) :
	currentRow(STARTING_ROW),
	currentCol(STARTING_COL),
	currentDir(STARTING_DIRECTION),
	currentPenDown(STARTING_PEN_POSITION)
	
{
	// initializing floor space to False
	for (auto &row : m_Floor)
	{
		for (auto &space : row)
		{
			space = false;
		}
	}
}

// will process
// the commands contained in array "cmds"	
void TurtleGraphics::processTurtleMoves(const std::array< int, TurtleGraphics::ARRAY_SIZE> cmds)
{

	// index of current command to process
	int currentIndex = 0;

	//control for exiting the loop
	bool doneProcessing = 
		((static_cast<Cmds>(cmds[currentIndex])==Cmds::END_OF_DATA) || cmds.size()==0);

	if (cmds.size() == 0)
	{
		cout << "Error! Commands array is empty.";
	}
	//processing commands
	while (!doneProcessing)
	{
		switch (static_cast<Cmds>(cmds[currentIndex]))
		{
		case Cmds::PEN_UP:
			currentPenDown = false;
			break;
		case Cmds::PEN_DWN:
			currentPenDown = true;
			break;
		case Cmds::TURN_RIGHT:
			currentDir = ((currentDir == UP) ? RIGHT : (currentDir + DIR_CHANGE));
			break;
		case Cmds::TURN_LEFT:
			currentDir = ((currentDir == RIGHT) ? UP : (currentDir - DIR_CHANGE));
			break;
		case Cmds::MOVE:
			move(currentDir, cmds[++currentIndex]);			
			break;
		case Cmds::DISPLAY:
			displayFloor();
			break;
		case Cmds::END_OF_DATA:
			doneProcessing = true;
			break;

		default:
			cerr << "ERROR! Unknown command! Reached the default case in swich inside " 
				<< "the processTurtleMoves() function of the TurtleGraphics class";
			break;
		}//end switch
		currentIndex++; //go to next comand to process
	}//end while
}

// will display floor on the screen
void TurtleGraphics::displayFloor() const
{
	// display floor using * for True and space for False
	for (auto &row : m_Floor)
	{
		for (auto &space : row)
		{
			cout << (space?DISPLAY_CHAR:' ');
		}
		cout << endl;
	}
	cout << endl;
}

//move the turtle on the floor, "draw" with true where passing
//and check for bounds
void TurtleGraphics::move(int direction, int steps)
{
	switch (direction)
	{
	case UP:
		while ((currentRow > 0) && (steps > 0))
		{
			currentPenDown ? (m_Floor[currentRow--][currentCol] = true) : currentRow--;
			steps--;
		}
		break;
	case RIGHT:
		while ((currentCol < NCOLS-1) && (steps > 0))
		{
			currentPenDown ? (m_Floor[currentRow][currentCol++] = true) : currentCol++;
			steps--;
		}
		break;
	case DOWN:
		while ((currentRow < NROWS-1) && (steps > 0))
		{
			currentPenDown ? (m_Floor[currentRow++][currentCol] = true) : currentRow++;
			steps--;
		} 
		break;
	case LEFT:
		while ((currentCol > 0) && (steps > 0))
		{
			currentPenDown ? (m_Floor[currentRow][currentCol--] = true) : currentCol--;
			steps--;
		}
		break;
	default:
		cerr << "ERROR! Invalid direction! Reached the default case in swich inside "
			<< "the move() function of the TurtleGraphics class";
		break;
	}
}