#include "BusquedaCentinela.h"
#include <vector>
using namespace std;

int busquedaCentinela(vector<int>& vec, int objetivo, int& comparaciones) {
    comparaciones = 0;
    if (vec.empty())
        return -1;

    int tamano = (int)vec.size();
    vec.push_back(objetivo); // centinela al final: el bucle siempre va a terminar

    int i = 0;
    while (vec[i] != objetivo) {
        comparaciones++;
        i++;
    }
    comparaciones++; // la comparacion que detuvo el bucle

    vec.pop_back(); // restaurar el vector

    if (i < tamano)
        return i;
    return -1;
}
