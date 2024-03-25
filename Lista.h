#pragma once
#include "Object.h"
#include "Integer.h"

class Lista {
protected:
	int size;
public:
	// Inserta un elemento a la lista en la posicion dada (entre 1 y n + 1)
	virtual bool inserta(Object*, int) = 0;

	// suprime(int) -> elimina el elemento de la lista en la posicion dada (entre 1 y n)
	virtual bool suprime(int) = 0;

	virtual Object* siguiente(int) = 0;

	virtual Object* anterior(int) = 0;

	// Elimina todos los elementos de la lista
	virtual void anula() = 0;

	// Retorna la primera posicion donde se encuentre el objeto enviado como parametro
	virtual int localiza(Object*) = 0;

	virtual void append(Object*) = 0;

	virtual Object* recupera(int) = 0;

	virtual Lista* localizaTodos(Object*) = 0;

	int getSize();

	bool isEmpty() {return size == 0;};

	virtual void imprime() = 0;

	virtual void suprimeTodos(Object*) = 0;

	// Regresa el primer elemento de la lista, si el elemento existe
	virtual Object* primero() = 0;
};