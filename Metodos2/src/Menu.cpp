#include "Menu.h"
#include "BusquedaArreglo.h"
#include "BusquedaCentinela.h"
#include "ListaEnlazada.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
using namespace std;

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

static int pedirEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor)
            return valor;
        cout << "Ingresa un numero entero valido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

static vector<int> pedirVector() {
    int n = pedirEntero("Cuantos elementos? ");
    vector<int> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(pedirEntero("  Elemento " + to_string(i + 1) + ": "));
    return vec;
}

void mostrarMenu() {
    limpiarPantalla();
    cout << "===== BUSQUEDA SECUENCIAL =====\n"
         << "1. Busqueda basica\n"
         << "2. Busqueda con centinela\n"
         << "3. Busqueda recursiva en lista enlazada\n"
         << "4. Comparar los tres metodos\n"
         << "0. Salir\n"
         << "Opcion: ";
}

void opcionBasica() {
    vector<int> vec = pedirVector();
    int objetivo = pedirEntero("Elemento a buscar: ");
    int comparaciones;

    int pos = busquedaBasica(vec, objetivo, comparaciones);

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones << "\n";
    pausar();
}

void opcionCentinela() {
    vector<int> vec = pedirVector();
    int objetivo = pedirEntero("Elemento a buscar: ");
    int comparaciones;

    int pos = busquedaCentinela(vec, objetivo, comparaciones);

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones << "\n";
    pausar();
}

void opcionRecursiva() {
    int n = pedirEntero("Cuantos nodos? ");
    Nodo* lista = nullptr;
    for (int i = 0; i < n; i++) {
        int dato = pedirEntero("  Nodo " + to_string(i + 1) + ": ");
        insertarNodo(lista, dato);
    }

    cout << "Lista: ";
    mostrarLista(lista);

    int objetivo = pedirEntero("Elemento a buscar: ");
    int comparaciones = 0;
    int pos = buscarEnLista(lista, objetivo, comparaciones);

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones << "\n";

    liberarLista(lista);
    pausar();
}

void opcionComparar() {
    vector<int> vec = pedirVector();
    int objetivo = pedirEntero("Elemento a buscar: ");

    int cmpB, cmpC, cmpR = 0;

    vector<int> vecC = vec;
    Nodo* lista = nullptr;
    for (int x : vec)
        insertarNodo(lista, x);

    int posB = busquedaBasica(vec, objetivo, cmpB);
    int posC = busquedaCentinela(vecC, objetivo, cmpC);
    int posR = buscarEnLista(lista, objetivo, cmpR);

    liberarLista(lista);

    cout << "\n" << left
         << setw(20) << "Metodo"
         << setw(12) << "Posicion"
         << "Comparaciones\n"
         << string(44, '-') << "\n"
         << setw(20) << "Basica"
         << setw(12) << (posB == -1 ? "N/A" : to_string(posB)) << cmpB << "\n"
         << setw(20) << "Centinela"
         << setw(12) << (posC == -1 ? "N/A" : to_string(posC)) << cmpC << "\n"
         << setw(20) << "Recursiva (lista)"
         << setw(12) << (posR == -1 ? "N/A" : to_string(posR)) << cmpR << "\n";
    pausar();
}
