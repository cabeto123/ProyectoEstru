#pragma once
#include "Object.h"

class Node
{
private:
    Node* anterior; // Puntero al nodo anterior
    Node* siguiente; // Puntero al siguiente nodo
    Object* contenido; // Contenido almacenado en el nodo
public:
    // Constructor por defecto
    Node();

    // M�todos para establecer y obtener el nodo anterior
    void setanterior(Node*);
    Node* getanterior();

    // M�todos para establecer y obtener el siguiente nodo
    void setsiguiente(Node*);
    Node* getsiguiente();

    // M�todos para establecer y obtener el contenido del nodo
    void setcontenido(Object*);
    Object* getcontenido();

    // Constructor que inicializa el nodo con un objeto dado
    Node(Object*);
};
