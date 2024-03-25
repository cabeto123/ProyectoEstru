#pragma once
#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include <string>

using namespace std;

class Alumno : public Object {
private:
	string Nombre;
	string Cuenta;
public:
	Alumno(); // Constructor vacio
	Alumno(string, string); // Constructor sobrecargado
	~Alumno(); // Destructor
	virtual string toString() override; // Pasar todo a tostring
	virtual bool equals(Object*) override; // Encontrar nombres iguales
	virtual Object* copy() override;
	string getNombre();
	string getCuenta();
	void setNombre(string);
	void setCuenta(string);
};