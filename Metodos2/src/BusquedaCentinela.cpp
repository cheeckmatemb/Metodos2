#include "BusquedaCentinela.hpp"

int BusquedaCentinela::buscar(std::vector<int>& vec, int objetivo) {
    comparaciones = 0;
    if (vec.empty())
        return -1;

    int tamOriginal = static_cast<int>(vec.size());
    vec.push_back(objetivo); // centinela: garantiza que el bucle termina sin verificar índice

    int i = 0;
    while (vec[i] != objetivo) {
        ++comparaciones;
        ++i;
    }
    ++comparaciones; // la comparación que terminó el bucle

    vec.pop_back(); // restaurar el vector a su estado original

    return (i < tamOriginal) ? i : -1;
}

int BusquedaCentinela::getComparaciones() const {
    return comparaciones;
}
