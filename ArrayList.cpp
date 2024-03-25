#include "ArrayList.h"

// Constructor: Inicializa un ArrayList con una capacidad predeterminada.
ArrayList::ArrayList() {
	capacity = 1000;
	array = new Object * [1000];
}

// Destructor: Libera la memoria asignada a los elementos y al array dinámico.
ArrayList::~ArrayList() {
	for (int i = 0; i < size; i++) delete array[i];
	delete[] array;
}

// Inserta un objeto en la posición especificada del ArrayList.
// Si la posición es mayor que la capacidad actual, se redimensiona el ArrayList.
// Devuelve true si se pudo insertar correctamente, false en caso contrario.
bool ArrayList::inserta(Object* objeto, int pos) {
	if (pos == size + 1 && pos > capacity)
		resize();
	if (pos > 0 && pos <= size + 1 && pos <= capacity) {
		for (int i = size - 1; i >= pos - 1; i--)
			if (i != capacity - 1) array[i + 1] = array[i];
		array[pos - 1] = objeto;
		size++;
		return true;
	}
	else
		return false;
}

Object* ArrayList::recupera(int pos) {
	if (pos > 0 && pos <= size)
		return array[pos - 1];
	else
		return NULL;
}

void ArrayList::suprimeTodos(Object* objeto) {
	int nuevaPosicion = 0;
	int tam = size;
	for (int i = 0; i < tam; i++) {
		if (!objeto->equals(array[i])) {
			Object* pointer = array[i];
			array[i] = NULL;
			array[nuevaPosicion] = pointer;
			nuevaPosicion++;
		}	
		else {
			delete array[i]; 
			size--;
		}
	}
}

bool ArrayList::suprime(int pos) {
	if (!isEmpty()) {
		if (pos > 0 && pos <= size) {
			int movimiento = 0;
			for (int i = 0; i < size; i++) {
				if (pos - 1 == i) {
					delete array[i];
					movimiento++;
					
				}
				else {
					Object* objetoTemp = array[i];
					array[i] = NULL;
					array[i - movimiento] = objetoTemp;
				}
			}
			size--;
			return true;
		}
		return false;
	}
	return false;
}

// Imprime los elementos almacenados en el ArrayList.
void ArrayList::imprime() {
	for (int i = 0; i < size; i++) cout << "[" << array[i]->toString() << "]\n";
	cout << "\n";
}

// Metodo append
void ArrayList::append(Object* objeto) {
	inserta(objeto, size + 1);
}

// Metodo para localizar elementos en el ArrayList
int ArrayList::localiza(Object* objeto) {
	for (int i = 0; i < size; i++) if (array[i]->equals(objeto)) return i+1;
	return -1;

}

// Metodo para localizar todos los elementos del ArrayList
Lista* ArrayList::localizaTodos(Object* objeto) {
	ArrayList* nuevaLista = new ArrayList();
	for (int i = 0; i < size; i++) 
		if (array[i]->equals(objeto)) nuevaLista->append(new Integer(i + 1));
	return nuevaLista;
}

Object* ArrayList::siguiente(int par) {
	if (par > 0 && par <= size) return array[par];
	return NULL;
}

Object* ArrayList::anterior(int par) {
	if (par > 0 && par - 2 <= size - 1 && par - 2 >= 0) return array[par - 2];
	return NULL;
}

void ArrayList::anula() {
	for (int i = 0; i < size; i++) delete array[i];
	size = 0;
}

Object* ArrayList::primero() {
	if (!isEmpty()) 
		return array[0];
	return nullptr;
}

// Redimensiona el ArrayList aumentando su capacidad en 100 elementos.
void ArrayList::resize() {
	capacity += 100;
	Object** array2 = new Object * [capacity];
	for (int i = 0; i < size; i++) 
		array2[i] = array[i];
	delete array;
	array = array2;
}