#include "BusquedaArreglo.hpp"

int BusquedaArreglo::buscar(const std::vector<int>& vec, int objetivo) {
    comparaciones = 0;
    for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
        ++comparaciones;
        if (vec[i] == objetivo)
            return i;
    }
    return -1;
}

int BusquedaArreglo::getComparaciones() const {
    return comparaciones;
}
