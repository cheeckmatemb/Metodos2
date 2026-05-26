#include "BusquedaArreglo.h"
#include <vector>
using namespace std;

int busquedaBasica(const vector<int>& vec, int objetivo, int& comparaciones) {
    comparaciones = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        comparaciones++;
        if (vec[i] == objetivo)
            return i;
    }
    return -1;
}
