// Assignment 1 COMP 2617 
//
// These are the member-function implementations for the class Account defined in the Account.h file
//
// Author:  Voicu Chirtes
// Date: Feb. 3, 2015

#include <iostream>
#include "Account.h"

using namespace std;

//explicit constructor for the class Account
Account::Account(int balanceToSetInUSD)
{
	setBalance(balanceToSetInUSD);
}

//function to set the Account balance, it ensures the balance to set is positive
void Account::setBalance(int balanceToSetInUSD)
{
	if (balanceToSetInUSD >= 0)
	{
		balanceInUSD = balanceToSetInUSD;
	}
	else
	{
		cout << "Error: Initial balance cannot be negative.\n" << endl;
		balanceInUSD = 0;
	}
}

//function to get the Account balance
int Account::getBalance()
{
	return balanceInUSD;
}

//function to add an amount to the current balance, it checks the amount to credit is positive
void Account::credit(int amountToAddInUSD)
{
	if (amountToAddInUSD >= 0)
	{
		balanceInUSD += amountToAddInUSD;
	}
	else
	{
		cout << "Error: Credit amount cannot be negative.\n" << endl;
	}
}

//function to withdraw money from Account. It checks the amount to debit is positive
//It does not allow overdraft, negative balance left in the Account. 
void Account::debit(int amountToDebitInUSD)
{
	if (amountToDebitInUSD >= 0)
	{
		if (amountToDebitInUSD <= balanceInUSD) // check we have enoght money to complete the withdrawal
		{
			balanceInUSD -= amountToDebitInUSD;
		}
		else
		{
			cout << "Debit amount exceeded account balance.\n" << endl;
		}
	}
	else
	{
		cout << "Error: Debit amount cannot be negative.\n" << endl;
	}
}