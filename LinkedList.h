#pragma once
#include "Lista.h"
#include "Node.h"
class LinkedList :
	public Lista
{
public:
	Node* nodo;
	//Constructor
	LinkedList();
	//Destructor
	~LinkedList();
	//Metodo para insertar un elemento a la lista
	virtual bool inserta(Object*, int) override;
	//Metodo para borrar un elemento de la lista
	virtual bool suprime(int) override;
	//Metodo para obtener el siguiente elemento(de la posicion recibida) de la lista
	virtual Object* siguiente(int) override;
	//Metodo para obtener el elemento anterior(de la posicion recibida) de la lista
	virtual Object* anterior(int) override;
	//Metodo anula
	virtual void anula() override;
	//Metodo para localizar un elemento
	virtual int localiza(Object*) override;
	// Metodo para hacer append
	virtual void append(Object*) override;
	//Metodo que retoorna un elemento
	virtual Object* recupera(int) override;
	//Metodo para imprimir los elementos de la lista
	virtual void imprime() override;
	//Metodo que retorna el primer elemento de la lista
	virtual Object* primero() override;
};


