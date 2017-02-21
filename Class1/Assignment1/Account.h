// Assignment 1 COMP 2617 
//
// This is the Account class definition. A class that creates and manipulates Account objects that models accounts
// for a bank or financial institution. This is an initial design of the class with basic functionality
//
//The member functions are defined in the Account.cpp file
//
// Author:  Voicu Chirtes
// Date: Feb. 3, 2015

class Account
{
public:
	//explicit constructor for the class Account
	explicit Account(int balanceToSetInUSD);

	//function to set the Account balance
	void setBalance(int balanceToSetInUSD);

	//function to get the Account balance
	int getBalance();

	//function to add an amount to the current balance
	void credit(int amountToAddInUSD);

	//function to withdraw money from Account. It does not allow overdraft, negative balance left in the Account. 
	void debit(int amountToDebitInUSD);

private:
	int balanceInUSD; // the Account balance
};