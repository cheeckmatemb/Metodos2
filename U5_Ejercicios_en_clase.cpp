// U5_Ejercicios_en_clase.cpp
// Unidad 5 – Programación Orientada a Objetos con CLASES
// Ejercicios 1-5 en un único archivo, sin programación modular.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// ================================================================
//  EJERCICIO 1 – Clase Tanque
// ================================================================
class Tanque {
    double contenido;          // almacena cuánto hay en el tanque
public:
    static const int capacidad = 5000; // capacidad máxima (compartida por todas las instancias)

    // Constructor: tanque comienza vacío
    Tanque() : contenido(0.0) {}

    // Devuelve el contenido actual
    double getContenido() { return contenido; }

    // Agrega cantidad sin superar la capacidad
    void agregar(double cantidad) {
        contenido = (contenido + cantidad > capacidad) ? (double)capacidad : contenido + cantidad;
    }

    // Extrae cantidad sin bajar de cero
    void sacar(double cantidad) {
        contenido = (cantidad > contenido) ? 0.0 : contenido - cantidad;
    }

    // Elimina la mitad del contenido; si está vacío no hace nada
    void sacaMitad() {
        if (contenido > 0.0)
            contenido /= 2.0;
    }
};

// ================================================================
//  EJERCICIO 2 – Clase Sala
// ================================================================
class Sala {
private:
    string nombre;
    int    largo, ancho;
    bool   equipado;
public:
    // Constructor con todos los parámetros
    Sala(string n, int l, int a, bool e) : nombre(n), largo(l), ancho(a), equipado(e) {}

    // Getters inline
    inline string getNombre()   { return nombre;   }
    inline int    getAncho()    { return ancho;    }
    inline int    getLargo()    { return largo;    }
    inline bool   getEquipado() { return equipado; }

    // Superficie en m²
    int calcularArea() { return largo * ancho; }

    // Capacidad: 1 asistente cada 1.5 m²
    int calcularCapacidad() { return (int)(calcularArea() / 1.5); }

    // Alquiler: $45/m² equipada, $32/m² sin equipar
    int calcularAlquiler() { return calcularArea() * (equipado ? 45 : 32); }

    // Muestra todos los datos en consola
    void mostrarDatos() {
        cout << "  Nombre    : " << nombre << "\n"
             << "  Largo     : " << largo  << " m\n"
             << "  Ancho     : " << ancho  << " m\n"
             << "  Equipada  : " << (equipado ? "Si" : "No") << "\n"
             << "  Superficie: " << calcularArea()      << " m2\n"
             << "  Capacidad : " << calcularCapacidad() << " personas\n"
             << "  Alquiler  : $" << calcularAlquiler() << "\n";
    }
};

// ================================================================
//  EJERCICIO 3 – Clase Persona
// ================================================================
class Persona {
private:
    string nombre, ID;
    int    edad;
    char   sexo;
    double peso, altura;

    // Valida que el sexo sea 'H' o 'M'; si no, asigna 'H'
    void comprobarSexo(char s) {
        sexo = (s == 'H' || s == 'M') ? s : 'H';
    }

    // Genera ID: iniciales del nombre + número aleatorio de 3 cifras
    void generaID() {
        int num = rand() % 900 + 100;   // número entre 100 y 999
        string iniciales = "";
        bool nuevaPalabra = true;
        for (char c : nombre) {
            if (nuevaPalabra && c != ' ') { iniciales += c; nuevaPalabra = false; }
            if (c == ' ') nuevaPalabra = true;
        }
        ID = iniciales + to_string(num);
    }

public:
    Persona(string n, int e, char s, double p, double a)
        : nombre(n), edad(e), peso(p), altura(a) {
        comprobarSexo(s);
        generaID();
    }

    // Getters
    string getNombre()  { return nombre;  }
    int    getEdad()    { return edad;    }
    char   getSexo()    { return sexo;    }
    double getPeso()    { return peso;    }
    double getAltura()  { return altura;  }

    // Setters (ID no tiene setter, se genera internamente)
    void setNombre(string n) { nombre = n; }
    void setEdad(int e)      { edad = e;   }
    void setSexo(char s)     { comprobarSexo(s); }
    void setPeso(double p)   { peso = p;   }
    void setAltura(double a) { altura = a; }

    // IMC = peso / altura²
    // Retorna: -1 si IMC < 20, 0 si 20 <= IMC <= 25, 1 si IMC > 25
    int calcularIMC() {
        double imc = peso / (altura * altura);
        if (imc < 20.0)               return -1;
        if (imc >= 20.0 && imc <= 25.0) return  0;
        return 1;
    }

    // Devuelve true si la persona es mayor de edad
    bool esMayorDeEdad() { return edad >= 18; }

    // Imprime toda la información del objeto
    void mostrar() {
        cout << "  Nombre : " << nombre << "\n"
             << "  ID     : " << ID     << "\n"
             << "  Edad   : " << edad   << " años\n"
             << "  Sexo   : " << sexo   << "\n"
             << "  Peso   : " << peso   << " kg\n"
             << "  Altura : " << altura << " m\n";
    }
};

// ================================================================
//  EJERCICIO 4 – Clases Atleta y Carrera
// ================================================================
class Atleta {
private:
    string nombre, nacion;
    int    numero;
    float  tiempo;
public:
    // Constructor por defecto (necesario para arrays)
    Atleta() : nombre(""), nacion(""), numero(0), tiempo(0.0f) {}

    // Constructor con parámetros
    Atleta(string n, int num, string nac, float t)
        : nombre(n), nacion(nac), numero(num), tiempo(t) {}

    inline string getNombre() { return nombre; }
    inline string getNacion() { return nacion; }
    inline int    getNumero() { return numero; }
    inline float  getTiempo() { return tiempo; }

    // Operador de salida para imprimir un atleta directamente con cout
    friend ostream& operator<<(ostream& os, Atleta& a) {
        os << "  Nombre: " << a.nombre
           << " | Nacion: " << a.nacion
           << " | Numero: " << a.numero
           << " | Tiempo: " << a.tiempo << " s\n";
        return os;
    }
};

class Carrera {
private:
    Atleta* competidores;          // array dinámico de atletas
    int     distancia, numAtletas, indx;  // indx rastrea cuántos se agregaron
public:
    Carrera(int d, int n) : distancia(d), numAtletas(n), indx(0) {
        competidores = new Atleta[n];  // reserva memoria para n atletas
    }

    ~Carrera() { delete[] competidores; } // libera memoria al destruir el objeto

    // Agrega un atleta si aún hay lugar
    void addAtleta(Atleta& a) {
        if (indx < numAtletas) competidores[indx++] = a;
    }

    inline int getDistancia()     { return distancia;  }
    inline int getNumeroAtletas() { return numAtletas; }

    // Recorre el array y devuelve el atleta con menor tiempo
    Atleta ganador() {
        Atleta g = competidores[0];
        for (int i = 1; i < indx; i++)
            if (competidores[i].getTiempo() < g.getTiempo())
                g = competidores[i];
        return g;
    }

    // Imprime todos los competidores registrados
    void mostrarCompetidores() {
        cout << "  Carrera de " << distancia << " m — " << indx << " competidores:\n";
        for (int i = 0; i < indx; i++) cout << competidores[i];
    }
};

// ================================================================
//  EJERCICIO 5 – Clases Vagon y Tren
// ================================================================
class Vagon {
private:
    bool asientos[40];   // estado de cada asiento (true=ocupado, false=vacante)
    bool clase;          // false=primera clase, true=segunda clase
public:
    // Constructor sin clase: primera clase por defecto, todos los asientos vacantes
    Vagon() : clase(false) {
        for (int i = 0; i < 40; i++) asientos[i] = false;
    }

    // Constructor con clase: todos los asientos vacantes
    Vagon(bool c) : clase(c) {
        for (int i = 0; i < 40; i++) asientos[i] = false;
    }

    bool getAsiento(int ind)  { return asientos[ind]; }
    void setAsiento(int ind)  { if (ind >= 0 && ind < 40) asientos[ind] = true; }
    bool getClase()           { return clase;  }
    void setClase(bool c)     { clase = c;     }

    // Ocupa asientos aleatoriamente: 10% probabilidad en primera, 40% en segunda
    void ocupar() {
        int prob = clase ? 40 : 10;
        for (int i = 0; i < 40; i++)
            if ((rand() % 100) < prob) asientos[i] = true;
    }

    // Cuenta y devuelve la cantidad de asientos ocupados
    int asientosOcupados() {
        int cnt = 0;
        for (int i = 0; i < 40; i++) if (asientos[i]) cnt++;
        return cnt;
    }

    // Operador de salida: muestra clase y estado de cada asiento
    friend ostream& operator<<(ostream& os, Vagon& v) {
        os << "  Clase: " << (v.clase ? "Segunda" : "Primera")
           << " | Asientos ocupados: " << v.asientosOcupados() << "/40\n";
        for (int i = 0; i < 40; i++)
            os << "    Asiento " << (i + 1) << ": "
               << (v.asientos[i] ? "Ocupado" : "Vacante") << "\n";
        return os;
    }
};

class Tren {
private:
    Vagon* vagones;
    int    numeroPrimera, numeroSegunda;
    string salida, destino;
    int    precioPrimera, precioSegunda;
public:
    // Constructor: crea array de vagones y asigna la clase a cada uno
    Tren(int nP, int nS, string sal, string dest, int pP, int pS)
        : numeroPrimera(nP), numeroSegunda(nS),
          salida(sal), destino(dest),
          precioPrimera(pP), precioSegunda(pS) {
        vagones = new Vagon[nP + nS];
        for (int i = 0;  i < nP;      i++) vagones[i] = Vagon(false); // primera
        for (int i = nP; i < nP + nS; i++) vagones[i] = Vagon(true);  // segunda
    }

    ~Tren() { delete[] vagones; } // libera el array de vagones

    Vagon getVagon(int i) { return vagones[i]; }

    // Llena aleatoriamente los asientos de todos los vagones
    void llenar() {
        for (int i = 0; i < numeroPrimera + numeroSegunda; i++)
            vagones[i].ocupar();
    }

    // Calcula los ingresos totales: asientos ocupados × precio por clase
    int totalVentas() {
        int total = 0;
        for (int i = 0; i < numeroPrimera; i++)
            total += vagones[i].asientosOcupados() * precioPrimera;
        for (int i = numeroPrimera; i < numeroPrimera + numeroSegunda; i++)
            total += vagones[i].asientosOcupados() * precioSegunda;
        return total;
    }
};

// ================================================================
//  MAIN – Ejecuta los 5 ejercicios en secuencia
// ================================================================
int main() {
    srand(time(0)); // inicializa generador de números aleatorios una sola vez

    // ── Ejercicio 1: Tanque ──────────────────────────────────────
    cout << "\n=== EJERCICIO 1: TANQUE ===\n";
    Tanque t;
    t.agregar(100.0);
    cout << "Contenido inicial: " << t.getContenido() << "\n";
    while (t.getContenido() >= 1.0) {
        t.sacaMitad();
        cout << "  sacaMitad() -> " << t.getContenido() << "\n";
    }
    cout << "El contenido final es: " << t.getContenido() << "\n";

    // ── Ejercicio 2: Sala ────────────────────────────────────────
    cout << "\n=== EJERCICIO 2: SALA ===\n";
    Sala s1("Sala 1", 12,  8, true);
    Sala s2("Sala 2", 20, 18, false);
    Sala s3("Sala 3", 15, 12, true);
    Sala salas[] = {s1, s2, s3};

    cout << "\nDatos de Sala 1:\n";
    s1.mostrarDatos();

    int eventos[4] = {200, 50, 100, 150};
    cout << "\nSalas disponibles por evento:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Evento " << (i + 1) << " (" << eventos[i] << " asistentes):\n";
        for (int j = 0; j < 3; j++)
            if (salas[j].calcularCapacidad() >= eventos[i])
                cout << "  La sala " << salas[j].getNombre()
                     << " tiene capacidad para " << eventos[i] << " personas\n";
    }

    // ── Ejercicio 3: Persona ─────────────────────────────────────
    cout << "\n=== EJERCICIO 3: PERSONA ===\n";
    string pNombres[3];
    int    pEdades[3];
    char   pSexos[3];
    double pPesos[3], pAlturas[3];

    cin.ignore(); // descarta el '\n' pendiente antes de usar getline
    for (int i = 0; i < 3; i++) {
        cout << "\nPersona " << (i + 1) << ":\n";
        cout << "  Nombre : ";    getline(cin, pNombres[i]);
        cout << "  Edad   : ";    cin >> pEdades[i];
        cout << "  Sexo (H/M): "; cin >> pSexos[i];
        cout << "  Peso (kg) : "; cin >> pPesos[i];
        cout << "  Altura (m): "; cin >> pAlturas[i];
        cin.ignore(); // descarta el '\n' tras el último cin >>
    }

    Persona* personas[3];
    for (int i = 0; i < 3; i++)
        personas[i] = new Persona(pNombres[i], pEdades[i], pSexos[i], pPesos[i], pAlturas[i]);

    cout << "\n--- Resultados ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPersona " << (i + 1) << ":\n";
        personas[i]->mostrar();

        int imc = personas[i]->calcularIMC();
        if      (imc == -1) cout << "  Estado IMC: Bajo peso (IMC < 20)\n";
        else if (imc ==  0) cout << "  Estado IMC: Peso ideal (20 <= IMC <= 25)\n";
        else                cout << "  Estado IMC: Sobrepeso (IMC > 25)\n";

        cout << "  Mayor de edad: " << (personas[i]->esMayorDeEdad() ? "Si" : "No") << "\n";
        delete personas[i];
    }

    // ── Ejercicio 4: Atleta y Carrera ────────────────────────────
    cout << "\n=== EJERCICIO 4: ATLETA Y CARRERA ===\n";
    Carrera carr1(1000, 3);
    Atleta  a1("Pancho", 1, "Mexico",   9.1f);
    Atleta  a2("Chacho", 3, "Colombia", 3.6f);
    Atleta  a3("Robert", 2, "Chile",    6.9f);
    carr1.addAtleta(a1);
    carr1.addAtleta(a2);
    carr1.addAtleta(a3);
    carr1.mostrarCompetidores();
    Atleta gan = carr1.ganador();
    cout << "\nGanador:\n" << gan;

    // ── Ejercicio 5: Vagon y Tren ────────────────────────────────
    cout << "\n=== EJERCICIO 5: VAGON Y TREN ===\n";
    Vagon v;
    v.ocupar();
    v.setClase(true);
    cout << "\nEstado del vagón:\n" << v;

    Tren tren(4, 7, "Aguascalientes", "Calvillo", 20, 10);
    tren.llenar();
    cout << "\nTotal de ventas del tren: $" << tren.totalVentas() << "\n";

    return 0;
}
