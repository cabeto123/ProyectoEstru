#pragma once
#include "Lista.h"

class ArrayList : public Lista {
private:
    int capacity;
    Object** array;
	void resize();
public:
	// Constructor vacio
	ArrayList(); 

	//Destructor
	~ArrayList();
		
	// Metodo inserta
	virtual bool inserta(Object*, int) override; 

	// Metodo suprime
	virtual bool suprime(int) override; 

	// Metodo siguiente
	virtual Object* siguiente(int) override; 

	// Metodo anterior
	virtual Object* anterior(int) override; 

	// Metodo anula
	virtual void anula() override; 

	// Metodo localiza
	virtual int localiza(Object*) override; 

	// Metodo append
	virtual void append(Object*) override; 

	// Metodo recupera
	virtual Object* recupera(int) override; 

	// Metodo localiza
	virtual Lista* localizaTodos(Object*) override; 

	// Metodo imprime
	virtual void imprime() override; 

	// Metodo suprimeTodos
	virtual void suprimeTodos(Object*) override; 

	// Metodo "primero"
	virtual Object* primero() override; 
};