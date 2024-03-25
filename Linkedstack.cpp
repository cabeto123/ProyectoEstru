#include "Linkedstack.h"

Linkedstack::Linkedstack()
{

}//Constructor vacio de la clase LinkedStack

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
}//Método para agregar un objeto a la pila.


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
}//Método para quitar y devolver el elemento superior de la pila.

Object* Linkedstack::top()
{
	return this->tope->getcontenido();
}//Método para obtener el elemento superior de la pila sin quitarlo.

bool Linkedstack::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}//Método para verificar si la pila está vacía

void Linkedstack::clear()
{
	this->tope = nullptr;
	size = 0;
}//Método para vaciar la pila

void Linkedstack::print()
{
	Node* nodoaux = this->tope;
	for (int i = 1; i <= this->size; i++)
	{
		cout << "[" << nodoaux->getcontenido()->toString() << "]" << endl;
		nodoaux = nodoaux->getsiguiente();
	}
}//Método para imprimir todos los elementos de la pila

