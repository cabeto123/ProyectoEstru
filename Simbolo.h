#pragma once
#include "Object.h"

class Simbolo :public Object
{
public:
	char simbolo;
	Simbolo(char simbolo);


	virtual bool equals(Object*) override;

	virtual string toString()override;

	virtual Object* copy() override;

};

