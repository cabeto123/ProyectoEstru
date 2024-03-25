#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
}//Constructor vacío de la LinkedQueue

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
}//Agrega un elemento a la LinkedQueue si el tamaño es mayor a 0. Si es igual a 0, asigna el objeto ingresado en un nodo inicializado como primero y ultimo en la cola

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
	
}//Si hay Nodos en la cola, recupera el primero en un nodo temp y asigna el siguiente como el primero. Retorna el objeto en el nodo temp

Object* LinkedQueue::peek()
{
	if(primero == NULL)
		return nullptr;
	return primero->getcontenido();
	
}//Retorna el objeto del primer de no estar vacio

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
	
}//Imprime toda la cola

void LinkedQueue::dequeueAll()
{
	if (ultimo) 
		delete ultimo;
	ultimo = NULL;
	primero = NULL;
	size = 0;
}//Desconecta la cola entera y asi, eliminandola

LinkedQueue::~LinkedQueue()
{
	if (ultimo) 
		delete ultimo;
}//Destructor de LinkedQueue
