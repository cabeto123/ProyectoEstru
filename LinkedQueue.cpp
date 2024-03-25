#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
}

void LinkedQueue::queue(Object* objeto)
{
	if (primero == NULL) {
		primero = new Node(objeto);
		ultimo = primero;
		size++;
	}
	else {
		Node* temp = new Node(objeto);
		ultimo->setsiguiente(temp);
		ultimo = temp;
		ultimo->setsiguiente(NULL);
		size++;
	}
}

Object* LinkedQueue::dequeue()
{
	if (primero == NULL)
		return nullptr;
	
	Node* temp = primero;
	if (primero->getsiguiente() != NULL)
		primero = primero->getsiguiente();
	else
		primero = NULL;
	size--;
	if (primero == NULL)
		ultimo = NULL;
	return temp->getcontenido();
	
}

Object* LinkedQueue::peek()
{
	if(primero == NULL)
		return nullptr;
	return primero->getcontenido();
	
}

void LinkedQueue::printQueue()
{
	if (primero != NULL) {
		Node* temp = primero;
		cout << "{";
		for(int i = 0; i<size-1;i++) {
			cout << temp->getcontenido()->toString()<<",";
			temp = temp->getsiguiente();
		}
		cout << temp->getcontenido()->toString()<<"}\n";
	}
	
}

void LinkedQueue::dequeueAll()
{
	if (ultimo) 
		delete ultimo;
	ultimo = NULL;
	primero = NULL;
	size = 0;
}

LinkedQueue::~LinkedQueue()
{
	if (ultimo) 
		delete ultimo;
}
