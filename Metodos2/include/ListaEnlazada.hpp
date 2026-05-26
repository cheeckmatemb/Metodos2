#ifndef LISTA_ENLAZADA_HPP
#define LISTA_ENLAZADA_HPP

class ListaEnlazada {
public:
    ListaEnlazada();
    ~ListaEnlazada();
    ListaEnlazada(const ListaEnlazada& otra);
    ListaEnlazada& operator=(const ListaEnlazada& otra);

    void insertar(int dato);
    int buscarRecursivo(int objetivo);
    int getComparaciones() const;
    void mostrar() const;

private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    int comparaciones;

    int buscarRecursivoAux(Nodo* nodo, int objetivo, int posicion);
    void copiarDesde(const ListaEnlazada& otra);
    void liberar();
};

#endif
