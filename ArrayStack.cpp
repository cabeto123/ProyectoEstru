#include "ArrayStack.h"
ArrayStack::ArrayStack() {
	almacenamiento = 100;
	array = new Object * [almacenamiento];
	size = 0;
}

void ArrayStack::push(Object* obj) {
	if (size + 1 > almacenamiento) {
		resize();
	}
	array[size] = obj;
	size++;
}

Object* ArrayStack::top() {
	if (size) {
		return array[size - 1];
	}
	return NULL;
}

Object* ArrayStack::pop() {
	if (size) {
		size--;
		Object* retorno = array[size];
		array[size] = NULL;
		return retorno;
	}
	else {
		return NULL;
	}
}

bool ArrayStack::isEmpty() {
	if (!size) {
		return true;
	}
	return false;
}

void ArrayStack::print() {
	for (int i = size - 1; i >= 0; i--) {
		cout << "[" + array[i]->toString() + "]\n";
	}
	cout << "\n";
}

void ArrayStack::resize() {
	almacenamiento += 100;
	Object** newArray = new Object * [almacenamiento];

	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}
void ArrayStack::clear() {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
	delete[] array;
	size = 0;
}

ArrayStack::~ArrayStack() {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
	delete[] array;
}