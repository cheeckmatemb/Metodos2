#include "ListaEnlazada.h"
#include <iostream>
using namespace std;

void insertarNodo(Nodo*& cabeza, int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }

    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr)
        actual = actual->siguiente;
    actual->siguiente = nuevo;
}

int buscarEnLista(Nodo* nodo, int objetivo, int& comparaciones, int posicion) {
    if (nodo == nullptr)
        return -1;
    comparaciones++;
    if (nodo->dato == objetivo)
        return posicion;
    return buscarEnLista(nodo->siguiente, objetivo, comparaciones, posicion + 1);
}

void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr)
            cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void liberarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
