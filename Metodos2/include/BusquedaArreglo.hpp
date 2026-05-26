#ifndef BUSQUEDA_ARREGLO_HPP
#define BUSQUEDA_ARREGLO_HPP

#include <vector>

class BusquedaArreglo {
public:
    int buscar(const std::vector<int>& vec, int objetivo);
    int getComparaciones() const;

private:
    int comparaciones = 0;
};

#endif
