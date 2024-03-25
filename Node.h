#pragma once
#include "Object.h"
class Node
{
private:
	Node* anterior;
	Node* siguiente;
	Object* contenido;
public:
	Node();
	void setanterior(Node*);
	void setsiguiente(Node*);
	Node* getsiguiente();
	Node* getanterior();
	void setcontenido(Object*);
	Object* getcontenido();

	Node(Object*);
};
