// Assignment 6 Solution: TurtleGraphics.h
// Declaration of class TurtleGraphics.
// Member functions are defined in TurtleGraphics.cpp.
// Original Author: Bob Langelaan
// Author: Voicu Chirtes
// Date: Mar 17, 2015

#pragma once
#include <array>

class TurtleGraphics
{
private:
	const static size_t NROWS = 22;  // number of rows in floor
	const static size_t NCOLS = 70;  // number of colums in floor

	const static int STARTING_ROW = 0;    // row that turtle will start in
	const static int STARTING_COL = 0;    // column that turtle will start in

	const static int STARTING_DIRECTION = 6; // direction that turtle 
	                      // will be facing at the start
                          // 6 as in 6 o'clock on an analog clock
                          // The other 3 possible values are 3,9 and 12 o'clock
	//possible directions using analog clock
	const static int DOWN = 6;
	const static int UP = 12;
	const static int LEFT = 9;
	const static int RIGHT = 3;

	//direction increment for changing position
	const static int DIR_CHANGE = 3;

	const static bool STARTING_PEN_POSITION = false; // Pen will be up when 
	                            // program starts
                                // false means pen up, true means pen down
	
	const static char DISPLAY_CHAR = '*'; // the character used to 
								// display a marked area on the floor

	void displayFloor() const;  // will display floor on the screen

	//move the turtle on the floor, "draw" with true where passing
	//and check for bounds
	void move(int direction, int steps); 

	std::array <std::array <bool, NCOLS>, NROWS> m_Floor;   // floor on which turtle will draw

	// data members to keep track of current position and direction
	int currentRow;
	int currentCol;
	int currentDir;

	//keep track of pen position. True if pen is down.
	int currentPenDown;

public:
	const static int ARRAY_SIZE = 250;

	TurtleGraphics(void); //ctor will init. floor to all "false" values, 
	                      //     as well as initialization of other data members
	void processTurtleMoves( const std::array< int, ARRAY_SIZE> );  // will process
	                   // the commands contained in array "commands"	
};
// available commands
enum class Cmds : unsigned short 
{ PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9};
