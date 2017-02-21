//
// Purpose:  Read in 2 positive integral numbers with up to MAX_DIGITS digits, add them together
// and display the result.
//
// Note: If result is more than MAX_DIGITS, an INCORRECT result will be displayed. Therefore
//      if reading in 2 numbers with n digits, and the result may be n+1 digits, MAX_DIGITS should
//      be set to n+1 to ensure the correct result will be calculated and displayed.
//
// Author: 
// Date:   
//

#include <iostream>
#include <conio.h>

using namespace std;

// Function prototypes
void readNumber(unsigned short []);
void writeNumber(const unsigned short []);
void addNumbers(const unsigned short [], const unsigned short [], unsigned short []);

//global constants
const unsigned int MAX_DIGITS = 30; // Largest result that can be calculated!

int main()
{
	//Declare variables

	// Read in 2 numbers
	cout << "Enter in the first number (max " << MAX_DIGITS << " digits):" << endl;
	readNumber(number1);

	cout << "\nEnter in the second number (max " << MAX_DIGITS << " digits):" << endl;
	readNumber(number2);

	// Add the 2 numbers into result
	addNumbers(number1, number2, result);

	// Display original numbers and answer
	cout << "\nThe result of adding the 2 numbers input is:\n\n ";
	writeNumber(number1);

	cout << "\n+";
	writeNumber(number2);

// You need to add some missing code here !!!

	cout << "\n ";
	writeNumber(result);

	cout << '\n' << endl;

	_getch(); // causes execution to pause until char is entered

}

// Function reads in number up to MAX_DIGITS digits in length
void readNumber(unsigned short input[])
{
	
}

// Function writes out number up to MAX_DIGITS digits in length
void writeNumber(const unsigned short output[])
{

}

// Function adds first 2 arrays (num1 and num2) and puts result in 3rd array -> sum
void addNumbers(const unsigned short num1[], const unsigned short num2[], unsigned short sum[])
{
	
}
