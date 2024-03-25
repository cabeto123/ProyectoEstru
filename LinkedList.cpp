#include "LinkedList.h"
LinkedList::LinkedList() {
	size = 0;
}

LinkedList::~LinkedList() {
	if (nodo) delete nodo;
}

bool LinkedList::inserta(Object* obj, int pos) {
	int actualPos = pos - 1;
	if (pos >= 0 && pos <= size + 1) {
		if (isEmpty()) {
			nodo = new Node(obj);

		}
		else {
			Node* insert = new Node(obj);
			Node* actual = nodo;
			for (int i = 0; i < actualPos - 1; i++)
				actual = actual->getsiguiente();
			insert->setanterior(actual);
			if (actual->getsiguiente()) {
				insert->setsiguiente(actual->getsiguiente());
				insert->getsiguiente()->setanterior(insert);
			}
			actual->setsiguiente(insert);
		}
		size++;
		return true;
	}

	return false;

}

void LinkedList::append(Object* obj) {
	inserta(obj, size + 1);
}

Object* LinkedList::recupera(int pos) {

	if (pos > 0 && pos <= size) {
		Node* nodeT = NULL;
		for (int i = 0; i < pos; i++)
			if (!i) nodeT = nodo;
			else nodeT = nodeT->getsiguiente();
		return nodeT->getcontenido();
	}
	return NULL;
}

Object* LinkedList::siguiente(int pos) {
	if (pos > 0 || pos < size - 1) return recupera(pos + 1);
	else return NULL;
}

Object* LinkedList::anterior(int pos) {
	int posA = pos - 1;
	if (pos > 1 || pos <= size) {
		if (posA >= 0 && posA < size) return recupera(posA);
	}

	return NULL;
}

void LinkedList::anula() {
	delete nodo;
	size = 0;
}

void LinkedList::imprime() {
	if (!isEmpty()) {
		Node* node = nodo;
		cout << "{" << nodo->getcontenido()->toString() << "}\n";
		while (node = node->getsiguiente()) cout << "{" << node->getcontenido()->toString() << "}\n";
		cout << "\n";
	}
}


bool LinkedList::suprime(int pos) {
	int posA = pos - 1;
	if (posA >= 0 && posA < size) {
		Node* nodoTemp = NULL;
		if (!posA) {
			nodoTemp = nodo;
			nodo = nodo->getsiguiente();
		}
		else if (posA == size - 1) {
			for (int i = 0; i < size; i++)
				if (!i) nodoTemp = nodo;
				else nodoTemp = nodoTemp->getsiguiente();
			nodoTemp->getanterior()->setsiguiente(NULL);
		}
		else {
			for (int i = 0; i < pos; i++)
				if (!i) nodoTemp = nodo;
				else nodoTemp = nodoTemp->getsiguiente();
			nodoTemp->getanterior()->setsiguiente(nodoTemp->getsiguiente());
			nodoTemp->getsiguiente()->setanterior(nodoTemp->getanterior());

		}
		nodoTemp->setsiguiente(NULL);
		delete nodoTemp;
		size--;
		return true;
	}
	return false;
}

Object* LinkedList::primero() {
	if (nodo) return nodo->getcontenido();
	return NULL;
}

int LinkedList::localiza(Object* ptr) {
	Node* temp = NULL;
	for (int i = 0; i < size; i++) {
		if (!i) temp = nodo;
		else temp = temp->getsiguiente();
		if (temp->getcontenido()->equals(ptr)) return i + 1;
	}
	return -1;
}

