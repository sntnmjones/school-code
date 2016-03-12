#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>

struct Item
{
	int upc;
	std::string desc; 
	std::string cost; 
	bool tax; 
	int quan;
};

class Inventory
{
public:
	Inventory();
	// public variables //
	static const int MAX_INV = 50;
	Item inventory[MAX_INV];
	std::ofstream outFile;



	/*******************************************************************************
	* Function Name: getInventory()
	* Parameters: None
	* Return Value: void
	* Purpose: preps register to begin processing transactions
	*******************************************************************************/
	void getInventory(std::string);



	/*******************************************************************************
	* Function Name: getBufferLength()
	* Parameters: std::ifstream&
	* Return Value: int
	* Purpose: Returns the length of the input file
	*******************************************************************************/
	int getBufferLength(std::ifstream&);



	/*******************************************************************************
	* Function Name: fillBuffer()
	* Parameters: std::ifstream&
	* Return Value: void
	* Purpose: Streams the input file into a char* array buffer.
	*******************************************************************************/
	void fillBuffer(std::ifstream&);



	/*******************************************************************************
	* Function Name: fillInventory()
	* Parameters: char*, int
	* Return Value: void
	* Purpose: Loops through buffer and assigns values to a Struct Item and injects
				them into a struct array.
	*******************************************************************************/
	void fillInventory(char*, int);



	/*******************************************************************************
	* Function Name: echoToScreen()
	* Parameters: None
	* Return Value: void
	* Purpose: Loops through inventory[] and mirrors items to file Receipt.txt and
				to the console.
	*******************************************************************************/
	void echoToScreen();



	/*******************************************************************************
	* Function Name: upcToStringArray()
	* Parameters: std::string
	* Return Value: void
	* Purpose: checks to see if the upc the user input is the same as the on in
				inventory[]
	*******************************************************************************/
	bool upcToStringArray(std::string);

private:
	int inInventory; // Items in inventory[]
	int bufferLength; // Number of chars in buffer
	std::ifstream inFile; // input text file
	char *buffer; // dynamic buffer
	Item newItem;
};

