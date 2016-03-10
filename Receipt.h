#pragma once
#include<iostream>
#include<fstream>

class Receipt
{
public:
	Receipt();
	std::ofstream outFile;
	void prepareReceipt(std::string);
	~Receipt();

private:

};