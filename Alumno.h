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
	virtual bool equals(Object*) override; // Compara el numero de cuenta de dos Alumnos
	virtual Object* copy() override; //Envia una copia del Alumno
	string getNombre(); //Getter de atributo Nombre
	string getCuenta(); //Getter de atributo Cuenta
	void setNombre(string); //Setter de atributo Nombre
	void setCuenta(string); //Setter de atributo Cuenta
};