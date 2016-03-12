#pragma once
#include"Inventory.h"

class HMI : public Inventory
{
public:
	// public variables //
	HMI();



	/*******************************************************************************
	* Function Name: strToFloat()
	* Parameters: string
	* Return Value: float
	* Purpose: Converts string input to float value
	*******************************************************************************/
	float strToFloat(std::string);



	/*******************************************************************************
	* Function Name: closeStuff()
	* Parameters: None
	* Return Value: void
	* Purpose: Closes the output file
	*******************************************************************************/
	void closeStuff();



	/*******************************************************************************
	* Function Name: cashierInput()
	* Parameters: None
	* Return Value: void
	* Purpose: Contains instructions and functions that allow the user to input and
				extract information, including upc, prod description, quantity
				desired, etc.
	*******************************************************************************/
	void cashierInput();



	/*******************************************************************************
	* Function Name: upcPrompt()
	* Parameters: None
	* Return Value: int
	* Purpose: Prompts the user for upc input
	*******************************************************************************/
	int upcPrompt();



	/*******************************************************************************
	* Function Name: quantityPrompt()
	* Parameters: None
	* Return Value: int
	* Purpose: Gets the quantity of product the user requests
	*******************************************************************************/
	int quantityPrompt();



	/*******************************************************************************
	* Function Name: fillNewArray()
	* Parameters: int, int
	* Return Value: Item
	* Purpose: Passes in the upc number and quantity desired. Fetches the matching
				upc struct and returns it to be added to the cashierInputArray[]
	*******************************************************************************/
	Item fillNewArray(int, int);



	/*******************************************************************************
	* Function Name: calculateTax()
	* Parameters: float, bool, int
	* Return Value: float
	* Purpose: Passes in float cost, bool tax, and int quantity to calculate and 
				return total tax
	*******************************************************************************/
	float calculateTax(float, bool, int);



	/*******************************************************************************
	* Function Name: printLineToReceipt()
	* Parameters: string, int, float, bool
	* Return Value: void
	* Purpose: Prints struct info to receipt and console
	*******************************************************************************/
	void printLineToReceipt(std::string, int, float, bool);

private:
	std::string upcInput;
	std::string quantInput;
	Item cashierInputArray[MAX_INV];
	float parsedCost;
	float taxTotal;
	float subTotal;
	float grandTotal;
};