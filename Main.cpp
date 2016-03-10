#include<iostream>
#include"Inventory.h"
#include"Receipt.h"
#include"HMI.h"

int main()
{
	using namespace std;
	string fileIn = "Inventory.txt";
	string fileOut = "Receipt.txt";

	HMI hmi;	
	
	hmi.prepareReceipt(fileOut);
	hmi.getInventory(fileIn);
	hmi.userPrompt();

	hmi.closeStuff();
	system("pause");
	return 0;
};