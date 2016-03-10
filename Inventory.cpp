#include"Inventory.h"

// struct Item
//{
//	int upc;
//	std::string desc;
//	std::string cost;
//	bool tax;
//};

Inventory::Inventory()
{
	inInventory = 0;
	bufferLength = 0;
	buffer = NULL;
}



void Inventory::getInventory(std::string fileIn)
{
	try
	{
		inFile.open(fileIn);
	}
	catch (const std::exception&)
	{
		std::cout << "File could not be retrieved.";
	}
	if (inFile.is_open())
	{
		getBufferLength(inFile);
		fillBuffer(inFile);
		fillInventory(buffer, bufferLength);
		echoToScreen();

		inFile.close();
	}
}

void Inventory::fillBuffer(std::ifstream& in)
{
	using namespace std;

	do
	{
		if (in.is_open())
		{
			bufferLength = getBufferLength(in);
			buffer = new char[bufferLength];
			in.read(buffer, bufferLength);
		}
		else
		{
			cout << "Input file is not open..." << endl;
			cout << "Attempting to open \"Inventory.txt\"..." << endl;
			in.open("Inventory.txt");
		}
	} while (!in.is_open());
}

int Inventory::getBufferLength(std::ifstream& inf)
{
	unsigned int len = 0;
	inf.seekg(0, inf.end);
	len = (int)inf.tellg();
	inf.seekg(0, inf.beg);
	return len;
}

void Inventory::fillInventory(char* buff, int len)
{
	using namespace std;
	int i = 0;
	int upcNum = 0;
	string itDesc = "";
	string itPrice = "";
	bool itTax = false;
	do
	{
		do
		{
			// assign upcNum
			if (buff[i] >= 48 && buff[i] <= 57)
			{
				string str = "";
				while (buff[i] != 32)
				{
					str += buff[i];
					i++;
				}
				upcNum = stoi(str, nullptr, 10);
			}
			// assign itDesc
			else if (buff[i] >= 97 && buff[i] <= 122)
			{
				string str = "";
				while (buff[i] != 32)
				{
					str += buff[i];
					i++;
				}
				itDesc = str;
			}
			// assign itPrice
			else if (buff[i] == 36)
			{
				string str = "";
				while (buff[i] != 32)
				{
					str += buff[i];
					i++;
				}
				itPrice = str;
			}
			// assign itTax
			else if (buff[i] == 78 || buff[i] == 84)
			{
				switch (buff[i])
				{
				case 78:
					itTax = false;
					break;
				case 84:
					itTax = true;
					break;
				}
			}
			i++;
		} while (buff[i] != 10 && i < len || buff[i + 1] == -51);

		newItem.upc = upcNum;
		newItem.desc = itDesc;
		newItem.cost = itPrice;
		newItem.tax = itTax;

		bool moreToSearch;
		int location = 0;

		moreToSearch = (location < inInventory);

		while (moreToSearch)
		{
			switch (newItem.upc < inventory[location].upc)
			{
			case false:
				moreToSearch = false;
				break;
			case true:
				if (location + 1 == inInventory)
				{
					moreToSearch = false;
					break;
				}
				else
				{
					location++;
					moreToSearch = (newItem.upc < inventory[location].upc);
					break;
				}
			}
		}
		for (int index = inInventory; index > location; index--)
			inventory[index] = inventory[index - 1];

		inventory[location] = newItem;
		inInventory++;

	} while (i < bufferLength);
}

void Inventory::echoToScreen()
{
	using namespace std;
	outFile.open("Receipt.txt");
	int z = 0;
	cout << endl;
	cout << "Items in inventory:" << endl;
	outFile << "Items in inventory:" << endl;

	while (z < inInventory)
	{
		int in = inventory[z].upc;
		string strg = inventory[z].desc;
		string cst = inventory[z].cost;
		bool boo = inventory[z].tax;
		string me;
		if (boo)
		{
			me = "true";
		}
		else
		{
			me = "false";
		}
		if (outFile.is_open())
		{
			outFile << in << setw(5) << " " << left << setw(15) << strg << " " << right << setw(10) << cst << setw(5) << " " << left << me << endl;
		}


		cout << in << setw(5) << " " << left << setw(15) << strg << " " << right << setw(10) << cst << setw(5) << " " << left << me << endl;
		z++;
	}
	cout << endl;
}

bool Inventory::upcToStringArray(std::string str)
{
	using namespace std;
	string upcString = "";
	string userInputStr = "";
	int i = 0;
	int upcTemp = 0;
	ostringstream convert;
	bool match = false;

	do
	{
		upcTemp = inventory[i].upc; // takes the upc int and stores in int upcTemp
		convert << upcTemp; // stores int into ostringstream object
		upcString = convert.str(); // converts int to string
		i++;
	} while (i < inInventory && upcString != userInputStr);

	if (upcString == userInputStr)
	{
		return match;
	}
	else
	{
		return !match;
	}
}

//void Inventory::emptyInventory()
//{
//	Item* tempPtr;
//	int i = 0;
//	while (newItem != NULL)
//	{
//		tempPtr = newItem;
//		newItem = inventory[i].next;
//		delete tempPtr;
//		i++;
//	}
//	delete[] inventory;
//}