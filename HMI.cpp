#include"HMI.h"

HMI::HMI()
{
	upcInput = "";
	quantInput = 0;
}

void HMI::userPrompt()
{
	using namespace std;
	HMI hmi;
	bool match;

	do
	{
		cout << "Please enter a 5 digit UPC from above: " << endl;
		getline(cin, upcInput);

		match = hmi.upcToStringArray(upcInput);

		if (!match)
		{
			cout << "You have entered an invalid upc. Please try again." << endl;
		}
	} while (!match);
	
	

	cout << "Please enter quantity from 1 - 100. " << endl;
	cin >> quantInput;
	cout << endl << endl;
}

void HMI::closeStuff()
{
	outFile.close();
	//emptyInventory();
}

HMI::~HMI()
{

}