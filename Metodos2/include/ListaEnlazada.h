#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarNodo(Nodo*& cabeza, int dato);
int buscarEnLista(Nodo* nodo, int objetivo, int& comparaciones, int posicion = 0);
void mostrarLista(Nodo* cabeza);
void liberarLista(Nodo*& cabeza);

#endif
