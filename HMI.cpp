#include"HMI.h"

HMI::HMI()
{
	upcInput = "";
	quantInput = "";
	taxTotal = 0.00;
	subTotal = 0.00;
	grandTotal = 0.00;
}

float HMI::strToFloat(std::string str)
{
	float cost = stof(str);
	return cost;
}

int HMI::quantityPrompt()
{
	using namespace std;
	int quantity = 0;

	while (quantity < 1 || quantity > 100)
	{
		if (upcInput == "0")
		{
			break;
		}

		cout << "Please enter quantity from 1 - 100. " << endl;
		getline(cin, quantInput);
		try
		{
			quantity = stoi(quantInput); // takes input and converts from string to int.
		}
		catch (const std::exception&)
		{
			cout << "Please enter a number between 1 - 100" << endl;
		}
		cout << endl;

		if (quantity < 1 || quantity > 100)
		{
			cout << "Your quantity is out of range. Please try again" << endl;
		}
		else
		{
			outFile << quantInput << endl; // prints line on receipt
			return quantity;
		}
	}
}

int HMI::upcPrompt()
{
	using namespace std;
	bool match = false;

	while (match == false)
	{
		cout << "Please enter a 5 digit UPC from above: " << endl;
		getline(cin, upcInput);

		if (upcInput == "0") // checks to see if user is done inputting values
		{
			break;
		}

		match = upcToStringArray(upcInput); // compares user input to upc numbers in inventory,
											//   returns 'match' if found.	
		
		if (match == false)
		{
			cout << "You have entered an invalid upc. Please try again." << endl;
		}
		else
		{
			outFile << upcInput << " "; // prints upc number on receipt
			int retVal = stoi(upcInput); //converts string back to int for further processing
			return retVal;
		}
	}

}

Item HMI::fillNewArray(int upc, int quan)
{
	int i = 0;
	int upcNum;

	while (upc != inventory[i].upc)
	{
		i++;
	}
	inventory[i].quan = quan; // writes quantity desired to the new array
	return inventory[i];
}

float HMI::calculateTax(float cost, bool tax, int quant)
{
	float taxReturn = 0.00;

	if (tax == true) // if item is taxable...
	{
		taxReturn = (cost * .075) * quant;
	}
	else
	{
		taxReturn = 0.00;
	}

	return taxReturn;
}

void HMI::cashierInput()
{
	using namespace std;
	cout.setf(ios::fixed, ios::floatfield); // set fixed floating format
	cout.precision(2); // sets precision to 0.00
	int newArrayIter = 0; // iterator for cashierInputArray[]
	taxTotal = 0.00; 
	subTotal = 0.00;
	grandTotal = 0.00;

	do
	{
		int upcNumber = 0; 
		int quantNumber = 0;

		upcNumber = upcPrompt(); // stores upc input in var upcNumber

		if (upcInput != "0") // if user enters valid upc
		{
			quantNumber = quantityPrompt(); // stores user's desired quantity in int quantNumber

			// fills position in cashierInputArray with the matching upc number's struct information
			cashierInputArray[newArrayIter] = fillNewArray(upcNumber, quantNumber);

			// parses the string cost to float parsedCost for calculations
			parsedCost = strToFloat(cashierInputArray[newArrayIter].cost);
		}
		
		// multiplies parsedCost by tax rate (if applicable), and then multiplies by quantity
		taxTotal += calculateTax(parsedCost, cashierInputArray[newArrayIter].tax, quantNumber);
		subTotal += parsedCost * quantNumber;		

		newArrayIter++;
	} while (upcInput != "0");

	grandTotal = taxTotal + subTotal;

	outFile << endl << "Customer's Items" << endl;
	cout << endl << "Customer's Items" << endl;

	int i = 0;
	while (i < newArrayIter - 1)
	{
		float flCost = strToFloat(cashierInputArray[i].cost);
		string tOut = "N";
		// converts tax true/false to strings T or N
		if (cashierInputArray[i].tax == true)
		{
			tOut = "T";
		}

		outFile << cashierInputArray[i].desc << setw(7) << " " <<
			cashierInputArray[i].quan << " @ " << right << 
			cashierInputArray[i].cost <<
			setw(15) << right << cashierInputArray[i].quan * flCost <<
			setw(3) << right << tOut << endl;

		cout << cashierInputArray[i].desc << setw(7) << " " <<
			cashierInputArray[i].quan << " @ " << right <<
			cashierInputArray[i].cost <<
			setw(15) << right << cashierInputArray[i].quan * flCost <<
			setw(3) << right << tOut << endl;
		i++;
	}

	outFile << endl << "Subtotal:" << setw(20) << right << subTotal << endl << 
		"Tax:" << setw(25) << right << taxTotal << endl << endl <<
		"Total:" << setw(23) << right << grandTotal << endl << endl;

	cout << "cashier done" << endl;

	cout << endl << "Subtotal:" << setw(20) << right  << subTotal << endl;
	cout << "Tax:" << setw(25) << right << taxTotal << endl << endl;
	cout << "Total:" << setw(23) << right << grandTotal << endl << endl;

	cout << "cashier done" << endl;
}


void HMI::closeStuff()
{
	outFile.close();
}

void HMI::printLineToReceipt(std::string desc, int num, float cos, bool tax)
{
	using namespace std;
	cout << desc << " " << num << " " << cos << " " << tax << endl;
	outFile << desc << " " << num << " " << cos << " " << tax << endl;
}