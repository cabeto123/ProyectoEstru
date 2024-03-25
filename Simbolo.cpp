#include "Simbolo.h"
#include <string>
using namespace std;

// Constructor: Inicializa un objeto Simbolo con el símbolo dado.
Simbolo::Simbolo(char simbolo)
{
	this->simbolo = simbolo;
}

// Comprueba si el objeto pasado es igual a este objeto Simbolo.
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

// Devuelve una representación de cadena del símbolo.
string Simbolo::toString()
{
	string s = "";
	s += this->simbolo;
	return s;
}

// Crea y devuelve una copia del objeto Simbolo.
Object* Simbolo::copy()
{
	Object* s = new Simbolo(this->simbolo);
	return s;
}

