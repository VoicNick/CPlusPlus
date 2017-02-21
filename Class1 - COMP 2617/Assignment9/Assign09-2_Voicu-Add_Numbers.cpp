// This proragm is for Assignment 9 COMP 2617
// Purpose:  Read in 2 positive integral numbers with up to MAX_DIGITS digits, add them together
// and display the result.
//
// Note: If result is more than MAX_DIGITS, an INCORRECT result will be displayed. Therefore
//      if reading in 2 numbers with n digits, and the result may be n+1 digits, MAX_DIGITS should
//      be set to n+1 to ensure the correct result will be calculated and displayed.
//
// Author: Voicu Chirtes
// Date:   4/8/2015
//

#include <iostream>
#include <conio.h>

using namespace std;

// Function prototypes
void readNumber(unsigned short []);
void writeNumber(const unsigned short []);
void addNumbers(const unsigned short [], const unsigned short [], unsigned short []);

//global constants
// Largest result that can be calculated!
// program will not display the leftmost digit of the result
// if the result sum is larger than MAX_DIGITS - this can be 
// improved in a future version.
const unsigned int MAX_DIGITS = 41; 

int main()
{
	//Declare variables
	unsigned short number1[MAX_DIGITS];
	unsigned short number2[MAX_DIGITS];
	unsigned short result[MAX_DIGITS];

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

	cout << '\n';
	for (int i = 0; i <= MAX_DIGITS; i++)
	{
		cout << '=';
	}

	cout << "\n ";
	writeNumber(result);

	cout << '\n' << endl;

	_getch(); // causes execution to pause until char is entered

}

// Function reads in number up to MAX_DIGITS digits in length
void readNumber(unsigned short input[])
{
	char nextChar = cin.get();
	unsigned short value = nextChar - '0';
	int counter = 0;

	// read numbers while they are smaller than MAX_DIGITS and valid 0-9 and
	// at least one digit was read - this deals with carry digit pressed 
	// at beginning of a number
	do
	{
		if (value >= 0 && value <= 9)
		{
			input[counter] = value;
			counter++;
		}
		nextChar = cin.get();
		value = nextChar - '0';
	} while (counter < MAX_DIGITS && ((value >= 0 && value <= 9) || counter == 0));	

	// decrement counter to have the value of actual digits entered
	counter--;

	// if array is not full, shift all values to right and fill with 0 the rest
	if (counter < MAX_DIGITS)
	{
		for (int i = MAX_DIGITS - 1; i >= 0; i--)
		{
			if (counter>=0)
			{
				input[i] = input[counter];
				counter--;
			}
			else
			{
				input[i] = 0;
			}
		}
	}
}

// Function writes out number up to MAX_DIGITS digits in length
void writeNumber(const unsigned short output[])
{
	int counter = 0;

	//print the leading spaces up until before last digit
	while (output[counter] == 0 && counter < MAX_DIGITS-1)
	{
		cout << ' ';
		counter++;
	}

	//print the actual until end
	while (counter < MAX_DIGITS)
	{
		cout << output[counter];
		counter++;
	}
}

// Function adds first 2 arrays (num1 and num2) and puts result in 3rd array -> sum
void addNumbers(const unsigned short num1[], const unsigned short num2[], unsigned short sum[])
{
	int counter = MAX_DIGITS - 1; // start from last element in the array
	int remain = 0; // carry over result when sum is over 10
	while (counter >= 0)
	{
		sum[counter] = (remain + num1[counter] + num2[counter]) % 10;
		// truncates the result to carry over
		remain = (remain + num1[counter] + num2[counter]) / 10;
		counter--;
	}
}