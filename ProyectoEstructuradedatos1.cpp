#include <iostream>
#include <string>
#include "ArrayList.h" 
#include "LinkedList.h" 
#include "LinkedStack.h"
#include "ArrayStack.h"
#include "Simbolo.h"
#include "Object.h"
using namespace std;
int operacionespila() {
    int opcion = 0;
    cout << "---- MENU ----" << endl;
    cout << "1.Empujar" << endl;
    cout << "2.Sacar" << endl;
    cout << "3.Ver tope" << endl;
    cout << "4.Verificar si esta vacia" << endl;
    cout << "5.Imprimir elementos" << endl;
    cout << "6.Salir" << endl;
    cout << "Ingrese su opción: " << endl;
    cin >> opcion;
    return opcion;
}
int mostrarMenuPrincipal() {
    int opcion;
    cout << "---- MENU ----" << endl;
    cout << "1. Trabajar con listas" << endl;
    cout << "2. Trabajar con pilas" << endl;
    cout << "3. Trabajar con colas" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese su opción: " << endl;
    cin >> opcion;
    return opcion;
}
int menutipopila() {
    int opcion = 0;
    cout << "---- MENU ----" << endl;
    cout << "1.Trabajar con ArrayStackOpcion: " << endl;
    cout << "2.Trabajar con LinkedStack" << endl;
    cout << "3.Regresar al Menú Principal" << endl;
    cin >> opcion;
    return opcion;
}
int mostrarMenuListas() {
    int opcionAgregar;
    cout << "---- Menu tipo de lista - SUBMENU ----" << endl;
    cout << "1. Trabajar con ArrayList" << endl;
    cout << "2. Trabajar con LinkedList" << endl;
    cout << "3. Regresar al menú principal" << endl;
    cout << "Ingrese su opción: " << endl;
    cin >> opcionAgregar;
    return opcionAgregar;
}

void trabajarConArrayList() {
    ArrayList lista;

    int opcionOperacion;

    bool salir = false;
    while (!salir) {
        cout << "---- Operaciones de Lista ----" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Imprimir elementos" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Borrar elemento" << endl;
        cout << "5. Ver si está vacía" << endl;
        cout << "6. Obtener elemento por posición" << endl;
        cout << "7. Obtener siguiente" << endl;
        cout << "8. Obtener anterior" << endl;
        cout << "9. Borrar todos los elementos" << endl;
        cout << "10. Regresar al menú anterior" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcionOperacion;

        switch (opcionOperacion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            salir = true;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    }

}

void trabajarConLinkedList() {
    LinkedList lista;

}

int main() {
    setlocale(LC_ALL, "spanish");
    int opciontipopila = 4;
    int operacioneslinkedstack = 4;
    bool salir = false;
    Linkedstack* l = new Linkedstack();
    ArrayStack* ast = new ArrayStack();
    Simbolo* s;
    Simbolo* sacar;
    char simbol;

    while (!salir) {
        int opcion = mostrarMenuPrincipal();

        switch (opcion) {
        case 1: {
            int opcionLista = mostrarMenuListas();
            switch (opcionLista) {
            case 1:
                trabajarConArrayList();
                break;
            case 2:
                trabajarConLinkedList();
                break;
            case 3:
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
            }
            break;
        }
        case 2:
            
            while (opciontipopila!=3)
            {
                opciontipopila = menutipopila();
                switch (opciontipopila)
                {
                case 1:
                    while (operacioneslinkedstack != 7) {
                        operacioneslinkedstack = operacionespila();
                        switch (operacioneslinkedstack)
                        {
                        case 1:cout << "Digite el simbolo :";
                            cin >> simbol;
                            s = new Simbolo(simbol);
                            ast->push(s);
                            break;
                        case 2:sacar = dynamic_cast<Simbolo*>(ast->pop());
                            cout << "El elemento sacado es :" + sacar->toString() << endl;
                            break;
                        case 3: sacar = dynamic_cast<Simbolo*>(ast->top());
                            cout << "El tope es " + sacar->toString() << endl;
                            break;
                        case 4:
                            if (ast->isEmpty())
                            {
                                cout << "La pila esta vacia" << endl;
                            }
                            else {
                                cout << "La pila no esta vacia" << endl;
                            }
                            break;
                        case 5:ast->print();
                            break;
                        case 6:ast->clear();
                            cout << "La pila se ha vaciado" << endl;
                            break;
                        }
                    }
                }
            }
                    break;
                case 2:
                    while (operacioneslinkedstack != 7) {
                        operacioneslinkedstack = operacionespila();
                        switch (operacioneslinkedstack)
                        {
                        case 1:cout << "Digite el simbolo :";
                            cin >> simbol;
                            s = new Simbolo(simbol);
                            l->push(s);
                            break;
                        case 2:sacar = dynamic_cast<Simbolo*>(l->pop());
                            cout << "El elemento sacado es :" + sacar->toString() << endl;
                            break;
                        case 3: sacar = dynamic_cast<Simbolo*>(l->tope->getcontenido());
                            cout << "El tope es " + sacar->toString() << endl;
                            break;
                        case 4:
                            if (l->isEmpty())
                            {
                                cout << "La pila esta vacia" << endl;
                            }
                            else {
                                cout << "La pila no esta vacia" << endl;
                            }
                            break;
                        case 5:l->print();
                            break;
                        case 6:l->clear();
                            cout << "La pila se ha vaciado" << endl;
                            break;
                        }
                    }
                }
            }

            
            break;
        case 3:
            // Trabajar con colas
            break;
        case 0:
            salir = true;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    }

    return 0;
}