#pragma once
#include "Object.h"
#include "TDACola.h"
class ArrayQueue :public TDACola
{
private:
	void expandir();
	Object** array;
	int maxSize;
public:
	ArrayQueue();
	virtual void queue(Object*);
	virtual Object* dequeue();
	virtual Object* peek();
	virtual void printQueue();
	virtual void dequeueAll() ;
	~ArrayQueue();
};

