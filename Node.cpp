#include "Node.h"

Node::Node()
{
	anterior = nullptr;
	siguiente = nullptr;
}

void Node::setanterior(Node* n)
{
	this->anterior = n;
}

void Node::setsiguiente(Node* s)
{
	this->siguiente = s;
}

Node* Node::getsiguiente()
{
	return this->siguiente;
}

Node* Node::getanterior()
{
	return this->anterior;
}

void Node::setcontenido(Object* c)
{
	this->contenido = c;
}

Object* Node::getcontenido()
{
	return this->contenido;
}

Node::Node(Object* c)
{
	this->contenido = c;
}
