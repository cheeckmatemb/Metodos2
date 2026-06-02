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
#include <chrono>
using namespace std;
using namespace chrono;

// Devuelve el tiempo en nanosegundos que tarda en ejecutarse una funcion
template<typename Func>
long long medirTiempo(Func f) {
    auto inicio = high_resolution_clock::now();
    f();
    auto fin    = high_resolution_clock::now();
    return duration_cast<nanoseconds>(fin - inicio).count();
}

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
    int pos;

    long long ns = medirTiempo([&]() {
        pos = busquedaBasica(vec, objetivo, comparaciones);
    });

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones
         << "  Tiempo: " << ns << " ns\n";
    pausar();
}

void opcionCentinela() {
    vector<int> vec = pedirVector();
    int objetivo = pedirEntero("Elemento a buscar: ");
    int comparaciones;
    int pos;

    long long ns = medirTiempo([&]() {
        pos = busquedaCentinela(vec, objetivo, comparaciones);
    });

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones
         << "  Tiempo: " << ns << " ns\n";
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
    int pos;

    long long ns = medirTiempo([&]() {
        pos = buscarEnLista(lista, objetivo, comparaciones);
    });

    if (pos == -1)
        cout << "No encontrado.";
    else
        cout << "Encontrado en posicion " << pos << ".";
    cout << "  Comparaciones: " << comparaciones
         << "  Tiempo: " << ns << " ns\n";

    liberarLista(lista);
    pausar();
}

void opcionComparar() {
    vector<int> vec = pedirVector();
    int objetivo = pedirEntero("Elemento a buscar: ");

    int cmpB, cmpC, cmpR = 0;
    int posB, posC, posR;

    vector<int> vecC = vec;
    Nodo* lista = nullptr;
    for (int x : vec)
        insertarNodo(lista, x);

    long long nsB = medirTiempo([&]() { posB = busquedaBasica(vec, objetivo, cmpB); });
    long long nsC = medirTiempo([&]() { posC = busquedaCentinela(vecC, objetivo, cmpC); });
    long long nsR = medirTiempo([&]() { posR = buscarEnLista(lista, objetivo, cmpR); });

    liberarLista(lista);

    cout << "\n" << left
         << setw(20) << "Metodo"
         << setw(12) << "Posicion"
         << setw(16) << "Comparaciones"
         << "Tiempo (ns)\n"
         << string(60, '-') << "\n"
         << setw(20) << "Basica"
         << setw(12) << (posB == -1 ? "N/A" : to_string(posB))
         << setw(16) << cmpB << nsB << "\n"
         << setw(20) << "Centinela"
         << setw(12) << (posC == -1 ? "N/A" : to_string(posC))
         << setw(16) << cmpC << nsC << "\n"
         << setw(20) << "Recursiva (lista)"
         << setw(12) << (posR == -1 ? "N/A" : to_string(posR))
         << setw(16) << cmpR << nsR << "\n";
    pausar();
}
