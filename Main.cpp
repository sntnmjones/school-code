#include<iostream>
#include<conio.h>
#include"Inventory.h"
#include"HMI.h"
HMI hmi;

/*******************************************************************************
* Program Name: Ass2
* Created Date: 3/12/16
* Created By: Troy Jones
* Purpose: To receive input from a cashier and translate that to a receipt and 
			console
* Acknowledgements: Cayton for the bailout.
*******************************************************************************/

int main()
{
	using namespace std;
	string fileIn = "Inventory.txt";
	string fileOut = "Receipt.txt";
	bool cont = true;
	hmi.getInventory(fileIn);

	string st;
	do
	{
		hmi.cashierInput();
		cout << endl << "Enter another customer? Enter 'y' or 'Y'" << endl;
		getline(cin, st);
		cout << endl << endl;
		if (st != "y" || st != "Y")
		{
			cout << "Invalid entry. Please try again." << endl;
		}
	} while (st == "y" || st == "Y");

	cout << "Thank you." << endl;
	hmi.closeStuff();
	system("pause");
	return 0;
};