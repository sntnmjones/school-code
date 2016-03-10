#pragma once
#include"Inventory.h"

class HMI : public Inventory
{
public:
	HMI();
	
	void closeStuff();
	void userPrompt();

	~HMI();

private:
	std::string upcInput;
	int quantInput;
};