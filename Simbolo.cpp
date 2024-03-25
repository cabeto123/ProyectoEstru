#include "Simbolo.h"
#include <string>
using namespace std;
Simbolo::Simbolo(char simbolo)
{
	this->simbolo = simbolo;
}
bool Simbolo::equals(Object* s) {
	if (dynamic_cast<Simbolo*>(s))
	{
		if (dynamic_cast<Simbolo*>(s)->simbolo == this->simbolo)
		{
			return true;
		}

	}


	return false;
}

string Simbolo::toString()
{
	string s = "";
	s += this->simbolo;
	return s;
}

Object* Simbolo::copy()
{
	Object* s = new Simbolo(this->simbolo);
	return s;
}

