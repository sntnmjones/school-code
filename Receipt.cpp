#include"Receipt.h"

Receipt::Receipt()
{

}

void Receipt::prepareReceipt(std::string fileOut)
{
	outFile.open(fileOut);
}

Receipt::~Receipt()
{
}