#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1: opcionBasica();    break;
        case 2: opcionCentinela(); break;
        case 3: opcionRecursiva(); break;
        case 4: opcionComparar();  break;
        case 0: cout << "Hasta luego.\n"; break;
        default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
