// Assignment 5 COMP 2617
// This program reads from keyboard and stores 20
// unique numbers (int within min and max) in a one-dimensional array.
//
// This is the solution for Assigment 5, Chapter 7 Ex 13 
//
// Author:	Voicu Chirtes
// Date:	Feb 18, 2015

// standard C++ libraries
#include <iostream> 
#include <array>
#include <iomanip>

using namespace std;

// limits of numbers accepted
const int MIN = 10;
const int MAX = 100;

const int COUNT = 20; // number of entries required
const size_t ARRAY_MAX_SIZE = COUNT; // max array size

array<int, ARRAY_MAX_SIZE> numbers = {}; // array to store the numbers
int validNumbers = 0; //the count of valid numbers in the array

//verifies if a number was entered before
bool isUnique(int);

int main()
{
	int number = 0;

	for (int i = 0; i < COUNT; i++)
	{
		cout << "\nEnter # " << i + 1 << " : ";
		cin >> number;
		
		// validate input
		while (cin.rdstate() || (number < MIN) || (number > MAX))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "The number entered is not in the valid range of " 
				<< MIN << " to " << MAX << endl;
			cout << "\nEnter # " << i + 1 << " : ";
			cin >> number;
		}

		//check and add to array if number is unique
		if (isUnique(number))
		{
			cout << "The number: " << number << " is unique" << endl;
			numbers[validNumbers] = number;
			validNumbers++;
		}
	}

	cout << "\n\nThe unique numbers are:" << endl;

	for (int i = 0; i < validNumbers; i++)
	{
		cout << setw(6) << numbers[i];
	}
	cout << '\n' << endl;

	system("pause");
	return 0;
}

//verifies if a number was entered before in array
bool isUnique(int number)
{
	for (int i = 0; i < validNumbers; i++)
	{
		if (number == numbers[i])
		{
			return false;
		}
	}
	return true; //if we got here number is not in array already
}