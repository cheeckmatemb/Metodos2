#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "BusquedaArreglo.hpp"
#include "BusquedaCentinela.hpp"
#include "ListaEnlazada.hpp"

class Menu {
public:
    void run();

private:
    BusquedaArreglo basica;
    BusquedaCentinela centinela;
    ListaEnlazada lista;

    void opcionBusquedaBasica();
    void opcionBusquedaCentinela();
    void opcionBusquedaRecursiva();
    void opcionComparar();

    int solicitarEntero(const std::string& prompt);
    std::vector<int> solicitarVector();
};

#endif
