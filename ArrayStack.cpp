#include "ArrayStack.h"
ArrayStack::ArrayStack() {
	almacenamiento = 100;
	array = new Object * [almacenamiento];
	size = 0;
}//Este constructor inicializa la pila. Establece la capacidad inicial de la pila en 100, inicializa un array de tamaño dinámico de tipo Object y establece el tamaño como 0

void ArrayStack::push(Object* obj) {
	if (size + 1 > almacenamiento) {
		resize();
	}
	array[size] = obj;
	size++;
}//Este método agrega un objeto al tope de la pila.

Object* ArrayStack::top() {
	if (size) {
		return array[size - 1];
	}
	return NULL;
}//Si la pila no está vacía, retorna el objeto en la parte superior de la pila sin eliminarlo

Object* ArrayStack::pop() {
	if (size) {
		size--;
		Object* retorno = array[size];
		array[size] = NULL;
		return retorno;
	}
	else {
		return NULL;
	}
}//Elimina y retorna el objeto en la parte superior de la pila dado que esta no esté vacía haciendo uso de un Object* llamado retorno para almacenar el elemento antes de eliminar.

bool ArrayStack::isEmpty() {
	if (!size) {
		return true;
	}
	return false;
}//Verifica si la pila está vacía usando la variable "size", retorna true si contiene elementos, de otra, retorna false

void ArrayStack::print() {
	for (int i = size - 1; i >= 0; i--) {
		cout << "[" + array[i]->toString() + "]\n";
	}
	cout << "\n";
}//Imprime el ArrayStack

void ArrayStack::resize() {
	almacenamiento += 100;
	Object** newArray = new Object * [almacenamiento];

	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}//Metodo incrementa tamaño del arreglo creando uno nuevo con un tamaño mayor y llena este nuevo arreglo con los elementos del antiguo.
void ArrayStack::clear() {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
	delete[] array;
	size = 0;
}//Este método elimina todos los objetos de la pila y libera la memoria asociada con ellos.

ArrayStack::~ArrayStack() {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
	delete[] array;
}//Destructor de la clase ArrayStack