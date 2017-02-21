// Assignment 4 COMP 2618, Voicu Chirtes
// This is the PhonNumber class implementation
// as required on the Assignment 4
// the class definition is in PhoneNumber.h file
//
// Author: Voicu Chirtes
// Date: May 19, 2015

#include <iostream>
#include <cstring>

#include "PhoneNumber.h"

using namespace std;

// overloaded input and output operators
ostream& operator<<(ostream& output, const PhoneNumber& theNumber)
{
	output << "(" << theNumber.areaCode << ") "
		<< theNumber.exchange << "-" << theNumber.line;

	return output;
}

istream& operator>>(istream& input, PhoneNumber& theNumber)
{
	// 
	const int SIZE = 15;
	// temprary storage for the full number in 
	// format (123) 456-7890 (area code) exchange - line
	char phone[SIZE]; 

	input.get(phone, SIZE);

	// validate the format of the input
	if (phone[0] != '(' || phone[4] != ')' || phone[5] != ' ' || phone[9] != '-')
	{
		// set failbit 
		input.clear(ios::failbit);
	}

	// input lenght should be size - 1
	if (strlen(phone) != (SIZE - 1))
	{
		// set failbit 
		input.clear(ios::failbit);
	}

	// char to test lenght of input
	char c = input.peek();

	// validate point a, lenght of input. Next character after 
	// we got the number must be end of file or end of line
	if (c != '\n' && c != EOF)
	{
		// set failbit 
		input.clear(ios::failbit);
	}

	// validate point b, area code and exchange do not
	// begin wiht 0 or 1
	if (phone[1] == '0' || phone[1] == '1' || phone[6] == '0' || phone[6] == '1')
	{
		// set failbit 
		input.clear(ios::failbit);
	}

	// validate point c, middle digit of the area code must be 0 or 1
	if (phone[2] != '0' && phone[2] != '1')
	{
		// set failbit 
		input.clear(ios::failbit);
	}
		
	// if we did not set failbit, the input must be valid, 
	// so we store it as a phone number object
	if (!input.fail())
	{
		// char delims[] = "()- ";
		strcpy(theNumber.phone, phone);
		strncpy(theNumber.areaCode, &phone[1], 3);
		theNumber.areaCode[3] = '\0';
		strncpy(theNumber.exchange, &phone[6], 3);
		theNumber.exchange[3] = '\0';
		strncpy(theNumber.line, &phone[10], 4);
		theNumber.line[4] = '\0';
	}
	return input;
}

// default constructor
PhoneNumber::PhoneNumber()
{
	// nothing to do here
}