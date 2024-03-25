#include "TDACola.h"

TDACola::TDACola()
{
	this->size = 0;
}

bool TDACola::isEmpty()
{
	if(size == 0)
		return true;
	return false;
}

int TDACola::getSize()
{
	return size;
}

TDACola::~TDACola()
{
}
