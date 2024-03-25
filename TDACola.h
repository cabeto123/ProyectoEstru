#pragma once
#include "Object.h"
class TDACola
{
protected:
	int size;
public:
	TDACola();
	virtual void queue(Object*) = 0;
	virtual Object* dequeue() = 0;
	virtual Object* peek() = 0;
	bool isEmpty();
	virtual void printQueue() = 0;
	virtual void dequeueAll() = 0;	
	int getSize();
	~TDACola();
};

