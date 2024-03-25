#include <iostream>
#include <locale.h>
#include "Node.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "Simbolo.h"
#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "Alumno.h"

//Metodo para revisar que el valor recibido sea numerico
bool esNumerico(string str) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

//Este metodo recibe un string, verifica que es un numero y lo almacena en memoria. Si el string no es un numero, o se encuentra fuera del rango establecido, regresara falso. Si estas condiciones se cumplen regresa verdadero
bool castearNumero(string str, int& var, int base, int limite) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}

	var = stoi(str);
	if (var < base || var > limite) return false;
	return true;
}

//Metodo que recibe una lista y un string que contenga el numero de cuenta y busca si se repite
bool estaRepetido(Lista* list, string numeroDeCuenta) {
	Alumno* temp = new Alumno("Temporal", numeroDeCuenta);
	for (int i = 1; i <= list->getSize(); i++) {
		if (dynamic_cast<Alumno*>(list->recupera(i))->equals(temp)) {
			delete temp;
			return true;
		}
	}
	delete temp;
	return false;
}

//Este metodo valida que el string recibido sea alguno de los caracteres "s , S, n , N"; si esta condicion se cumple, regresa verdadero; si no, regresa falso.
bool validacionSioNo(string parametro) {
	if (parametro.size() != 1 || (parametro.at(0) != 'n' && parametro.at(0) != 'N' && parametro.at(0) != 's' && parametro.at(0) != 'S')) return false;
	return true;
}


//Metodo para imprimir el menu de listas
void menuListas() {
	string input;
	int posicion = 0;
	int opcion = 0;
	Lista* list = NULL;
	while (opcion != 3) {
		string menuP = "\n\n ----MENÚ TIPO DE LISTAS----\n 1) Trabajar con ArrayList\n 2) Trabajar con LinkedList\n 3) Volver a menú principal\n Ingrese el Tipo de Lista a Usar: ";
		while (cout << menuP && (cin >> input) && !castearNumero(input, opcion, 1, 3)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " OPCION NO VALIDA(Fuera de Rango)\n";
			cout << " Ingrese una Nueva Opción Válida\n";
			cin.clear();
		}

		if (opcion == 1)
			list = new ArrayList();
		else if (opcion == 2)
			list = new LinkedList();

		//sub menu de opciones
		if (opcion != 3) {
			int menu = 0;

			string subM = "\n\n--> OPERACIONES DE LISTAS <--\n";
			subM += "  1) Insertar Elemento\n";
			subM += "  2) Imprimir Elementos\n";
			subM += "  3) Buscar Elemento\n";
			subM += "  4) Borrar Elemento\n";
			subM += "  5) Ver si está vacía\n";
			subM += "  6) Obtener Elemento por Posición\n";
			subM += "  7) Obtener Siguiente\n";
			subM += "  8) Obtener Anterior\n";
			subM += "  9) Borrar todos los Elementos (Anula)\n";
			subM += "  10) Regresar al Menú Anterior\n";
			subM += "  Ingrese una Opción del Menú: ";

			do {
				while (cout << subM && (cin >> input) && !castearNumero(input, menu, 1, 10)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << " OPCION NO VALIDA(Fuera de Rango)\n";
					cout << " Ingrese una Nueva Opción Válida\n";
				}

				Object* estudiante = NULL;

				switch (menu)
				{
				case 1: {
					//OPCION 1
					string nombreA;
					string Numcuenta;

					bool repeat = true;
					do {
						cin.clear();
						cin.ignore();
						cout << "\n Ingrese el nombre del alumno: ";
						getline(cin, nombreA);
						cout << " Ingrese el numero de cuenta del alumno : ";
						cin >> Numcuenta;

						while (!esNumerico(Numcuenta) || estaRepetido(list, Numcuenta)) {
							cout << " Error(Numero de cuenta Repetido)\n";
							cout << " Ingrese un Número de Cuenta Válido\n\n";
							cout << " Ingrese el numero de cuenta del alumno: ";
							cin >> Numcuenta;
						}

						estudiante = new Alumno(nombreA, Numcuenta);

						while (cout << "Ingrese posicion de alumno: " && cin >> input && !castearNumero(input, posicion, 1, list->getSize() + 1)) {
							cout << " Error(Posicion no válida)\n";
							cout << " Ingrese una Nueva Opción Válida\n";
						}

						list->inserta(estudiante, posicion);
						cout << "Alumno Agregado Correctamente" << endl;

						while (cout << "Desea ingresar de nuevo? [s/n] : " && cin >> input && !validacionSioNo(input)) {
							cout << " Error(Caracter no Válido)\n";
							cout << " Ingrese un 's' o 'n'\n";
						}
						if (input.at(0) == 'n' || input.at(0) == 'N') repeat = false;

					} while (repeat);
				}//Inserta Un Elemento En La Lista
					  break;
				case 2: {
					//Opcion 2
					cout << "\n------- Lista -------\n";
					list->imprime();
					cout << endl;
				}//Imprimir Elementos De La Lista
					  break;

				case 3: {
					//Opcion 3
					if (list->isEmpty()) {
						cout << " La lista no contiene ningun elemento\n\n";
					}
					else {
						printf("\n");
						cout << " Ingrese el numero de cuenta a buscar : " << endl;
						string Cuenta;
						cin >> Cuenta;

						while (!esNumerico(Cuenta)) {
							cout << " Error(Formato de numero de cuenta no válido)\n";
							cout << " Ingrese el numero de cuenta a buscar: " << endl;
							string strCuenta;
						}

						int posBuscar = list->localiza(new Alumno("", Cuenta));
						if (posBuscar > 0 && posBuscar <= list->getSize()) {
							cout << list->recupera(posBuscar)->toString() << ", Posición -> " << posBuscar << "." << endl;
						}else{
							cout << " Numero de cuenta no encontrado\n";
						}
					}
				}//Buscar Elemento En La Lista
					  break;

				case 4: {
					//Oppcion 4
					int posicionE = 0;
					cout << "\n Ingrese la posicion que desea eliminar: " << endl;
					cin >> posicionE;

					if (posicionE > 0 && posicionE <= list->getSize())
					{
						list->suprime(posicionE);
						cout << " Alumno eliminado exitosamente\n\n" << endl;
					}
					else {
						cout << " Error(Fuera de rango)\n\n";
					}
				}//Borrar Elemento De La Lista
					  break;

				case 5: {
					//Opcion 5
					if (list->isEmpty()) cout << "\n La lista esta vacia" << endl;
					else printf(" La lista contiene %d elemento(s)\n", list->getSize());

				}//Ver si la lista contiene elementos o esta vacia
					  break;

				case 6: {
					//Opcion 6

					cout << "\n Ingrese la posicion del elemento en la lista: " << endl;
					int posE;
					cin >> posE;

					if (posE > 0 && posE <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->recupera(posE);
						cout << estudiante->toString();
					}
					else {
						cout << " Error(Fuera de rango)\n\n";
					}
				}//Obtener elementos por posicion
					  break;

				case 7: {
					//Opcion 7

					cout << "\n Ingrese la posicion en la que desea conseguir el elemento siguiente: " << endl;
					int posE;
					cin >> posE;

					if (posE > 0 && posE + 1 <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->siguiente(posE);
						cout << estudiante->toString();
					}
					else {
						cout << "Error(Fuera de rango)\n\n";
					}
				}//Obtener Siguiente Elemento
					  break;

				case 8: {
					//Opcion 8

					cout << "\n Ingrese la posicion en la que desea conseguir el elemento anterior: " << endl;
					int posicionElemento;
					cin >> posicionElemento;


					if (posicionElemento - 1 > 0 && posicionElemento <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->anterior(posicionElemento);
						cout << estudiante->toString();
					}
					else {
						cout << " Error(Fuera de rango)\n\n";

					}
				}//Obtener Elemento Anterior
					  break;

				case 9: {
					//Opcion 9
					if (!list->isEmpty())
					{
						list->anula();
						cout << "\n Se ha Eliminado la Lista Exitosamente\n" << endl;
					}
					else { 
						cout << "\n La lista ya está Vacía\n" << endl;
					}
				}//Borrar todos los elementos(Anula)
					  break;
				}
			} while (menu != 10);
			if (list)
				delete list;
		}
	}//Fin while de tipo de lista
}//Fin Menu

 //Metodo para imprimir menu de stack
void menuPila() {
	int opcion = 0;
	TDAPila* stack = NULL;
	string input;
	//eleccion de tipo de pila
	do {
		string menuP = "\n---- MENÚ TIPOS DE PILAS ----\n  1) Trabajar con ArrayStack\n  2) Trabajar con LinkedStack\n  3) Volver a menú principal\n Ingrese Opción del Menú: ";
		while (cout << menuP && (cin >> input) && !castearNumero(input, opcion, 1, 3)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error(Fuera de rango)\n";
			cout << " Ingrese una Opción Válida\n";
			cin.clear();
		}

		//eleccion de stack
		if (opcion == 1)
			stack = new ArrayStack();
		else if (opcion == 2)
			stack = new Linkedstack();

		//sub menu de opciones
		if (opcion != 3) {
			int menu;
			string sub = "\n\n--> OPERACIONES EN PILAS <--\n";
			sub += "  1) Empujar(push)\n";
			sub += "  2) Sacar(pop)\n";
			sub += "  3) Ver Tope (top)\n";
			sub += "  4) Verificar si está vacía\n";
			sub += "  5) Imprimir elementos\n";
			sub += "  6) Borrar todos los elementos\n";
			sub += "  7) Regresar al Menú anterior\n";
			sub += "  Ingrese opción: ";

			//validacion para subMenu
			do {
				while (cout << sub && (cin >> input) && !castearNumero(input, menu, 1, 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << " Error(Fuera de rango)\n";
					cout << " Ingrese una Opción Válida\n";
				}

				char simbolo = ' ';
				Object* simboloA = NULL;
				string simboloIn;
				//operaciones de pilas

				switch (menu) {
				case 1:
					//Opcion 1
					while (cout << "\nIngrese un simbolo para agregar a la pila: " && cin >> simboloIn && simboloIn.size() > 1) {
						cout << "\nError(Solo se permite 1 caracter)\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					simboloA = new Simbolo(simboloIn.at(0));
					stack->push(simboloA);
					cout << " Simbolo Agregado" << endl;
					break;

				case 2:
					//Opcion 2
					//imprime y saca el ultimo elemento de la pila
					if (!stack->isEmpty()) {
						simboloA = stack->pop();
						cout << "\n Este símbolo salio de la pila : " << dynamic_cast<Simbolo*>(simboloA)->simbolo << "\n";
						delete simboloA;
					}
					else {
						cout << "\n La Pila Esta Vacía\n";
					}
					break;

				case 3:
					//Opcion 3
					//Revisa el siguiente elemento en la pila sin sacarlo
					if (!stack->isEmpty()) {
						simboloA = stack->top();
						cout << "\n El siguiente símbolo esta a la cima de la pila : " << dynamic_cast<Simbolo*>(simboloA)->simbolo << "\n";
					}
					else {
						cout << "\n No hay elementos en la Pila\n";
					}
					break;

				case 4:
					//Opcion 4
					//verificar si la pila está vacía
					if (stack->isEmpty()) cout << "\n La Pila Está vacía\n";
					else cout << "\n La Pila No esta Vacía\n";
					break;

				case 5:
					//Opcion 5
					//imprimir los elementos en la pila
					if (!stack->isEmpty()) {
						cout << "\n------- Pila -------\n";
						stack->print();
					}
					else {
						cout << "\n No hay elementos en la pila para imprimir\n";
					}
					break;

				case 6:
					//Opcion 6
					//vaciar la stack
					stack->clear();
					cout << "\n La pila se vació exitosamente" << endl;
					break;
				}
			} while (menu != 7);
			if (stack)
				delete stack;
		}


	} while (opcion != 3);
}


//metodo para imprimir el menu de colas
void menuCola() {
	int input = 0;
	TDACola* cola = NULL;

	do {
		string menuP = "\n---- MENÚ TIPOS DE COLAS ----\n  1) Trabajar con ArrayQueue\n  2) Trabajar con LinkedQueue\n  3) Volver a menú principal\n Ingrese Opción del Menú: ";
		while (cout << menuP && (!(cin >> input) || (input < 1 || input > 3))) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error(Fuera de rango)\n";
			cin.clear();
		}

		switch (input) {
		case 1: {
			cola = new ArrayQueue();
		}
			  break;

		case 2: {
			cola = new LinkedQueue();
		}
			  break;

		}

		int opcion = -1;
		int num = -1;
		if (input != 3) {
			do {
				string inputC;
				string menuCola = " \n\n--> OPERACIONES DE COLAS <--\n";
				menuCola += "  1) Encolar (Queue)\n";
				menuCola += "  2) Desencolar (Dequeue)\n";
				menuCola += "  3) Ver Frente (Peek)\n";
				menuCola += "  4) Vacia\n";
				menuCola += "  5) Imprime Cola\n";
				menuCola += "  6) Borrar los Elementos\n";
				menuCola += "  7) Regresar al Menu Anterior\n";
				menuCola += "Ingrese opción: ";

				while (cout << menuCola && (cin >> inputC) && !castearNumero(inputC, opcion, 1, 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << " Error(Fuera de Rango)\n";
				}

				Object* student = new Alumno();
				string nombre = "";
				string numCuenta;

				switch (opcion) {
				case 1: { //Agregar a la cola (Queue)
					//Opcion 1
					cin.ignore();
					cout << "\n Ingrese el nombre del alumno: ";
					cin >> nombre;

					cout << " Ingrese el numero de cuenta del alumno: ";
					cin >> numCuenta;

					while (!esNumerico(numCuenta)) {
						cout << " Ingrese una Nueva Cuenta Válida\n\n";
						cout << " Ingrese el numero de cuenta del alumno: ";
						cin >> numCuenta;
					}

					cola->queue(new Alumno(nombre, numCuenta));
					cout << " Alumno agregado a la cola correctamente" << endl;
				}
					  break;

				case 2: { //Quitar de la cola (Dequeue)
					//Opcion 2

					if (cola->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << " La Cola está vacia" << endl;
					}
					else {
						cout << "\n El Alumno sacado de la cola es : " << cola->dequeue()->toString() << endl;
					}
				}
					  break;

				case 3: { //Ver Frente (Peek)
					//Opcion 3

					if (cola->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << " La Cola está vacia" << endl;
					}
					else {
						cout << "\n El elemento en frente de la cola es: " << cola->peek()->toString() << endl;
					}
				}
					  break;

				case 4: { //Vaciar
					//Opcion 4

					if (cola->isEmpty()) {
						cout << "\n La Cola Está Vacía" << endl;
					}
					else {
						cout << "\n La Cola Tiene Elementos en Ella" << endl;
					}
				}
					  break;

				case 5: { //Imprimir Elementos
					//Opcion 5

					if (cola->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << " La Cola está vacia" << endl;
					}

					else {
						cout << endl << "\n------- Cola -------\n";
						cola->printQueue();
					}
					break;
				}
					  break;

				case 6: { //Borrar los Elementos
					//Opcion 6

					if (cola->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << " La Cola está vacia" << endl;
					}
					else {
						cola->dequeueAll();
						cout << "\n La Cola se ha limpiado correctamente" << endl;
					}
				}
					  break;

				case 7: { //Regresar al Menu Anterior
					//Opcion 7
				}
					  break;
				}

			} while (opcion != 7);
			if (cola)
				delete cola;
		}
	} while (input != 3);
}


int main() {
	setlocale(LC_ALL, "spanish");
	//validacion de entrada
	int opcion;
	cout << "Alejandro José Cardona Montoya - 12251125\n"
		<< "Juan David Flores Machuca - 12311155\n"
		<< "Lloyd Christopher Cooper Vásquez - 12211056\n"
		<< "Fernando José Padilla Oliva - 12141213\n"
		<< "Carlos Alberto Moncada Echeverria - 12251169\n";

	do {
		cout << "\n<<<<<---------------------------------->>>>>\n\n";
		cout << "========== MENÚ PRINCIPAL ==========\n";
		string input;
		string mensajeMenu = "  1) Trabajar con Listas\n  2) Trabajar con Pilas\n  3) Trabajar con Colas\n  4) Salir\n Ingrese Opción del Menú: ";
		while (cout << mensajeMenu && (cin >> input) && !castearNumero(input, opcion, 1, 4)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error(Fuera de Rango)\n\n";
			cout << "<<<<<<<<<< MENU PRINCIPAL >>>>>>>>>>\n";
		}


		switch (opcion) {
		case 1:
			menuListas();
			//menu de opcion de listas
			break;
		case 2:
			//menu de opciones de pilas
			menuPila();
			break;
		case 3:
			menuCola();
			//menu de opcion de colas
			break;
		}
	} while (opcion != 4);
}

