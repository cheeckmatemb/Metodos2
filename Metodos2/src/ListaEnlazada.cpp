#include "ListaEnlazada.hpp"
#include <iostream>

ListaEnlazada::ListaEnlazada() : cabeza(nullptr), comparaciones(0) {}

ListaEnlazada::~ListaEnlazada() {
    liberar();
}

ListaEnlazada::ListaEnlazada(const ListaEnlazada& otra) : cabeza(nullptr), comparaciones(otra.comparaciones) {
    copiarDesde(otra);
}

ListaEnlazada& ListaEnlazada::operator=(const ListaEnlazada& otra) {
    if (this != &otra) {
        liberar();
        comparaciones = otra.comparaciones;
        copiarDesde(otra);
    }
    return *this;
}

void ListaEnlazada::insertar(int dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    Nodo* actual = cabeza;
    while (actual->siguiente)
        actual = actual->siguiente;
    actual->siguiente = nuevo;
}

int ListaEnlazada::buscarRecursivo(int objetivo) {
    comparaciones = 0;
    return buscarRecursivoAux(cabeza, objetivo, 0);
}

int ListaEnlazada::getComparaciones() const {
    return comparaciones;
}

void ListaEnlazada::mostrar() const {
    Nodo* actual = cabeza;
    while (actual) {
        std::cout << actual->dato;
        if (actual->siguiente) std::cout << " -> ";
        actual = actual->siguiente;
    }
    std::cout << '\n';
}

int ListaEnlazada::buscarRecursivoAux(Nodo* nodo, int objetivo, int posicion) {
    if (!nodo) return -1;
    ++comparaciones;
    if (nodo->dato == objetivo) return posicion;
    return buscarRecursivoAux(nodo->siguiente, objetivo, posicion + 1);
}

void ListaEnlazada::copiarDesde(const ListaEnlazada& otra) {
    Nodo* actual = otra.cabeza;
    while (actual) {
        insertar(actual->dato);
        actual = actual->siguiente;
    }
}

void ListaEnlazada::liberar() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
