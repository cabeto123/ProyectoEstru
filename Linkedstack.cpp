#include "Linkedstack.h"

Linkedstack::Linkedstack()
{

}

void Linkedstack::push(Object* objeto)
{
	if (size == 0)
	{
		this->tope = new Node(objeto);
		this->size++;
	}
	else {
		Node* nuevotope = new Node(objeto);


		Node* anteriortope = this->tope;
		anteriortope->setanterior(nuevotope);
		nuevotope->setsiguiente(anteriortope);
		this->tope = nuevotope;
		size++;

	}
}

Object* Linkedstack::pop()
{
	if (size == 1)
	{

		size = 0;
		Object* salida = tope->getcontenido();
		this->tope = nullptr;
		return salida;


	}
	else {

		Object* salida = tope->getcontenido();
		Node* aux = tope->getsiguiente();
		this->tope = aux;
		size--;
		return salida;

	}
}

Object* Linkedstack::top()
{
	return this->tope->getcontenido();
}

bool Linkedstack::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

void Linkedstack::clear()
{
	this->tope = nullptr;
	size = 0;
}

void Linkedstack::print()
{
	Node* nodoaux = this->tope;
	for (int i = 1; i <= this->size; i++)
	{
		cout << "[" << nodoaux->getcontenido()->toString() << "]" << endl;
		nodoaux = nodoaux->getsiguiente();
	}
}

