#ifndef BUSQUEDA_CENTINELA_HPP
#define BUSQUEDA_CENTINELA_HPP

#include <vector>

class BusquedaCentinela {
public:
    int buscar(std::vector<int>& vec, int objetivo);
    int getComparaciones() const;

private:
    int comparaciones = 0;
};

#endif
