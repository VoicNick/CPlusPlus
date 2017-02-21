// Assignment 4 COMP 2618, Voicu Chirtes, ex 13.14
// This program uses the PhoneNumber class and 
// overloads the << and >> operatiors to allow
// direct operation on PhoneNumber class objects
//
// Author: Voicu Chirtes
// Date: May 19, 2015

#include <iostream>
#include "PhoneNumber.h"

using namespace std;

int main()
{
	PhoneNumber phone;



	do
	{
		cout << "Enter a phone number in the form (123) 456-7890:" << endl;
		cin >> phone;

		if (!cin.fail())
		{
			cout << "\nThe phone number entered was:  " << phone << endl << endl;
			cin.ignore(); // flush the buffer for next input
		}
		else
		{
			cout << "\nInvalid phone number entered.\n" << endl;
		}
	} while (!cin.fail());

	return 0;

}