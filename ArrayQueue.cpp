#include "ArrayQueue.h"



ArrayQueue::ArrayQueue()
{
	size = 0;
	maxSize = 50;
	array = new Object*[maxSize];
}
void ArrayQueue::expandir()
{
	maxSize += 5;
	Object** temp = new Object*[maxSize];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
}

void ArrayQueue::queue(Object* obj)
{
	if (size + 1 == maxSize)
		expandir();
	size += 1;
	array[size - 1] = obj;
}

Object* ArrayQueue::dequeue()
{
	if (size > 0) {
		Object* temp = array[0];
		array[0] = NULL;
		for (int i = 1; i <size; i++) {
			array[i - 1] = array[i];
		}
		size--;
		array[size] = NULL;
		
		return temp;
	}
	else
		return nullptr;
}

Object* ArrayQueue::peek()
{
	if (size > 0)
		return array[0];
	else
		return nullptr;
}

void ArrayQueue::printQueue()
{
	cout << "{";
	for (int i = 0; i < size; i++)
		if(i <size-1)
			cout << array[i]->toString()<<",";
		else
			cout << array[i]->toString();
	cout << "}" << endl;
}

void ArrayQueue::dequeueAll()
{
	if (size > 0) {
		for (int i = size - 1; i >= 0; i--)
			delete array[i];
	}
	delete[] array;
	size = 0;
}

ArrayQueue::~ArrayQueue()
{
	if (size > 0) {
		for (int i = size - 1; i >= 0; i--)
			delete array[i];
	}
	delete[] array;
	size = 0;
}
