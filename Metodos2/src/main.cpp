#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer antes de pausar
        switch (opcion) {
        case 1: opcionBasica();    break;
        case 2: opcionCentinela(); break;
        case 3: opcionRecursiva(); break;
        case 4: opcionComparar();  break;
        case 0: cout << "Hasta luego.\n"; break;
        default: cout << "Opcion invalida.\n"; pausar(); break;
        }
    } while (opcion != 0);

    return 0;
}
