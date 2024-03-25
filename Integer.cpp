#include "Integer.h"

Integer::Integer(int x) {
	this->element = x;
}

// Getter
int Integer::getElement() {
	return element;
}

// Setter
void Integer::setElement(int newElement) {
	this->element = newElement;
}


bool Integer::equals(Object* objeto) {
	if (dynamic_cast<Integer*>(objeto))
		if (element == dynamic_cast<Integer*>(objeto)->element) 
			return true;
	return false;
}

string Integer::toString() {
	return to_string(element);
}

Object* Integer::copy() {
	Object* temp = new Integer(element);
	return temp;
}