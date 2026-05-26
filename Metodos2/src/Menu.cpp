#include "Menu.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void Menu::run() {
    int opcion;
    do {
        cout << "\n===== BUSQUEDA SECUENCIAL =====\n"
             << "1. Busqueda basica (arreglo)\n"
             << "2. Busqueda con centinela (arreglo)\n"
             << "3. Busqueda recursiva (lista enlazada)\n"
             << "4. Comparar los tres metodos\n"
             << "0. Salir\n"
             << "Opcion: ";
        opcion = solicitarEntero("");
        switch (opcion) {
        case 1: opcionBusquedaBasica();     break;
        case 2: opcionBusquedaCentinela();  break;
        case 3: opcionBusquedaRecursiva();  break;
        case 4: opcionComparar();           break;
        case 0: cout << "Hasta luego.\n";   break;
        default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void Menu::opcionBusquedaBasica() {
    vector<int> vec = solicitarVector();
    int objetivo = solicitarEntero("Elemento a buscar: ");
    int pos = basica.buscar(vec, objetivo);
    if (pos == -1)
        cout << "No encontrado. Comparaciones: " << basica.getComparaciones() << '\n';
    else
        cout << "Encontrado en posicion " << pos << ". Comparaciones: " << basica.getComparaciones() << '\n';
}

void Menu::opcionBusquedaCentinela() {
    vector<int> vec = solicitarVector();
    int objetivo = solicitarEntero("Elemento a buscar: ");
    int pos = centinela.buscar(vec, objetivo);
    if (pos == -1)
        cout << "No encontrado. Comparaciones: " << centinela.getComparaciones() << '\n';
    else
        cout << "Encontrado en posicion " << pos << ". Comparaciones: " << centinela.getComparaciones() << '\n';
}

void Menu::opcionBusquedaRecursiva() {
    int n = solicitarEntero("Cantidad de nodos a insertar: ");
    ListaEnlazada lst;
    for (int i = 0; i < n; ++i) {
        int dato = solicitarEntero("  Nodo " + to_string(i + 1) + ": ");
        lst.insertar(dato);
    }
    cout << "Lista: ";
    lst.mostrar();
    int objetivo = solicitarEntero("Elemento a buscar: ");
    int pos = lst.buscarRecursivo(objetivo);
    if (pos == -1)
        cout << "No encontrado. Comparaciones: " << lst.getComparaciones() << '\n';
    else
        cout << "Encontrado en posicion " << pos << ". Comparaciones: " << lst.getComparaciones() << '\n';
}

void Menu::opcionComparar() {
    vector<int> vec = solicitarVector();
    int objetivo = solicitarEntero("Elemento a buscar: ");

    // Copiar para centinela porque lo modifica temporalmente
    vector<int> vecCentinela = vec;

    // Copiar en lista enlazada
    ListaEnlazada lst;
    for (int x : vec) lst.insertar(x);

    int posB = basica.buscar(vec, objetivo);
    int posC = centinela.buscar(vecCentinela, objetivo);
    int posR = lst.buscarRecursivo(objetivo);

    cout << "\n--- Comparacion de metodos ---\n"
         << left << setw(20) << "Metodo"
         << setw(12) << "Posicion"
         << "Comparaciones\n"
         << string(44, '-') << '\n'
         << setw(20) << "Basica"
         << setw(12) << (posB == -1 ? "N/A" : to_string(posB))
         << basica.getComparaciones() << '\n'
         << setw(20) << "Centinela"
         << setw(12) << (posC == -1 ? "N/A" : to_string(posC))
         << centinela.getComparaciones() << '\n'
         << setw(20) << "Recursiva (lista)"
         << setw(12) << (posR == -1 ? "N/A" : to_string(posR))
         << lst.getComparaciones() << '\n';
}

int Menu::solicitarEntero(const string& prompt) {
    int valor;
    while (true) {
        if (!prompt.empty()) cout << prompt;
        if (cin >> valor) return valor;
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

vector<int> Menu::solicitarVector() {
    int n = solicitarEntero("Cantidad de elementos: ");
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; ++i)
        vec.push_back(solicitarEntero("  Elemento " + to_string(i + 1) + ": "));
    return vec;
}
