// Assignment 4 COMP 2618, Voicu Chirtes
// This is the PhonNumber class definition
// as required on the Assignment 4
// the class implementation is in PhoneNumber.cpp file
//
// Author: Voicu Chirtes
// Date: May 19, 2015

#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <iostream>

class PhoneNumber 
{
   // overloaded input and output operators
   friend std::ostream& operator<<( std::ostream&, const PhoneNumber& );
   friend std::istream& operator>>( std::istream&, PhoneNumber& );

public:
   PhoneNumber(); // default constructor
private:
   char phone[ 15 ]; // holds phone number
   char areaCode[ 4 ]; // holds area code
   char exchange[ 4 ]; // holds exchange
   char line[ 5 ]; // holds line
}; // end class PhoneNumber

#endif
