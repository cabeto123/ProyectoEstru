#pragma once
#include "Node.h"
#include "TDACola.h"
class LinkedQueue :public TDACola
{
private:
	Node* primero;
	Node* ultimo;
public:
	LinkedQueue();
	virtual void queue(Object*);
	virtual Object* dequeue();
	virtual Object* peek();
	virtual void printQueue();
	virtual void dequeueAll();
	~LinkedQueue();
};

