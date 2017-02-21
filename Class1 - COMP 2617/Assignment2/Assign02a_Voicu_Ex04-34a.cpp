//Assignment 2a COMP 2617
//
// This is the solution for Assignemnt 2a, Chapter 4 Ex 34a 
// This program calculates the factorial of a non-negative number
// less than or equal to 20
//
// Author:	Voicu Chirtes
// Date:	Feb 8, 2015

# include <iostream> // using a standard C++ library

using namespace std;

int main() //function main begins program execution
{
	const int MAX_FACTORIAL = 20; // the max factorial that we can calculcate with this program

	int number = 0; // the number to calculate the factorial for
	long long int result = 1; // the calculated result initialized to lowest possible value, 1

	cout << "Enter a positive integer less than or equal to " << MAX_FACTORIAL << " : ";
	cin >> number;

	//ensures valid input
	while ((cin.rdstate()) || (number < 0) || (number > MAX_FACTORIAL)) //ensure valid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cerr << "Enter a positive integer less than or equal to " << MAX_FACTORIAL << " : ";
		cin >> number;
	}

	for (int i = number; i > 0; i--) // calculates the factorial
	{
		result *= i;
	}
	cout << '\n' << number << "! is " << result << '\n' << endl;
}