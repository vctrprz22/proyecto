// Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// Costos de Recursos
const int Costo_Comida = 50; // Costo de cada unidad de comida
const int Costo_Suero = 100; // Costo por aplicar suero
const int Costo_Medicina = 250; // Costo por aplicar medicina
const int Costo_Vacuna = 500; // Costo por aplicar vacuna

//Estados
const int VIVO            = 0;
const int MUERTO          = 1;

const int BIEN_ALIMENTADO = 0;
const int DESNUTRIDO      = 1;

const int SANO            = 0;
const int ENFERMO         = 1;

// Genera un número entero entre a y b
int numeroAleatorio(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// Genera un número decimal entre 0 y 1
double probabilidad() {
    return (double) rand() / (double) RAND_MAX;
}

// Clase Animal (base)

class Animal {
protected:
    int id;                  // identificador único
    string tipo;             // tipo de animal
    int comidaPorDia;        // comida que necesita por día
    int precio;              // precio del animal

    int vida;                // estado de vida (VIVO o MUERTO)
    int estadoComida;        // estado de nutrición (BIEN ALIMENTADO o DESNUTRIDO)
    int salud;               // estado de salud (SANO o ENFERMO)

    bool comioHoy;           // si comió hoy
    bool esCria;             // si es cría
    int diasEnfermo;         // días que lleva enfermo
    bool enfermedadGrave;    // si la enfermedad es grave (solo para las crías)
    int vacunas;             // cantidad de vacunas aplicadas

    static int contadorId;   // contador para generar IDs automáticos

public:
    // Constructor
    Animal(string _tipo, int _comida, int _precio, bool _cria = false) {
        tipo = _tipo;
        comidaPorDia = _comida;
        precio = _precio;
        esCria = _cria;
        id = ++contadorId;

        vida = VIVO;
        estadoComida = BIEN_ALIMENTADO;
        salud = SANO;
        comioHoy = false;
        diasEnfermo = 0;
        enfermedadGrave = false;
        vacunas = 0;
    }
  virtual ~Animal() {}

// Revisar salud (curación o muerte)
    void revisarSalud() {
        if (vida == MUERTO || salud == SANO) return;

        if (esCria) {
            if (enfermedadGrave) {
                if (diasEnfermo <= 0) {
                    vida = MUERTO;
                    cout << "La cría " << id << " (" << tipo << ") murió por enfermedad grave.\n";
                } else {
                    diasEnfermo--;
                }
            } else {
                diasEnfermo--;
                if (diasEnfermo <= 0) {
                    if (probabilidad() < 0.2) {
                        salud = SANO;
                        cout << "La cría " << id << " (" << tipo << ") se recuperó naturalmente.\n";
                    } else {
                        diasEnfermo = 1;
                    }
                }
            }
        } else {
            diasEnfermo--;
            if (diasEnfermo <= 0) {
                if (probabilidad() < 0.5) {
                    salud = SANO;
                    cout << "El animal " << id << " (" << tipo << ") se recuperó naturalmente.\n";
                } else {
                    diasEnfermo = 1;
                }
            }
        }
    }
static double probabilidadBase(string t, bool cria) {
    if (t == "Ave") {
        if (cria) return 0.04;
        else return 0.02;
    }

    if (t == "Mamífero") {
        if (cria) return 0.02;
        else return 0.01;
    }

    if (t == "Reptil") {
        if (cria) return 0.03;
        else return 0.015;
    }

    if (t == "Pez") {
        if (cria) return 0.05;
        else return 0.025;
    }

    if (t == "Anfibio") {
        if (cria) return 0.04;
        else return 0.02;
    }

    return 0.0; // si no coincide con ningún tipo
}
 virtual void mostrarDescripcion() = 0;

    // Mostrar información del animal
    void mostrar() {
        cout << "ID: " << id 
             << " | Tipo: " << tipo
             << " | Vida: " << (vida == VIVO ? "Vivo" : "Muerto")
             << " | Nutrición: " << (estadoComida == BIEN_ALIMENTADO ? "Bien" : "Desnutrido")
             << " | Salud: " << (salud == SANO ? "Sano" : "Enfermo")
             << " | Comida diaria: " << comidaPorDia
             << " | Precio: " << precio;

        if (esCria) cout << " | (Cría)";
        cout << endl;

        cout << "  Descripción: ";
        mostrarDescripcion();
    }
};

// Getters
    int getId() { return id; }
    string getTipo() { return tipo; }
    int getComida() { return comidaPorDia; }
    int getPrecio() { return precio; }
    bool getEsCria() { return esCria; }
    int getVida() { return vida; }


// Posibilidad de enfermarse
    void chanceEnfermar() {
        if (vida == MUERTO || salud == ENFERMO) return;

        double p = probabilidadBase(tipo, esCria);

        // Cada vacuna reduce la probabilidad
        for (int i = 0; i < vacunas; i++) {
            p = p * 0.8;
        }

        if (probabilidad() < p) {
            salud = ENFERMO;
            cout << "El animal " << id << " (" << tipo << ") se enfermó.\n";

            if (esCria) {
                diasEnfermo = numeroAleatorio(1, 3);
                if (probabilidad() < 0.5) enfermedadGrave = true;
            } else {
                diasEnfermo = 1;
            }
        }
    }
// Clase Ave
class Ave : public Animal {
public:
    Ave(int p, bool c = false) : Animal("Ave", 1, p, c) {
        // El ave necesita 1 unidad de comida al día
    }

    void mostrarDescripcion() {
        cout << "Un ave es un vertebrado con plumas, alas y pone huevos.\n";
    }
};

// Clase Mamífero
class Mamifero : public Animal {
public:
    Mamifero(int p, bool c = false) : Animal("Mamífero", 5, p, c) {
        // El mamífero necesita 5 unidades de comida al día
    }

    void mostrarDescripcion() {
        cout << "Un mamífero tiene sangre caliente y amamanta a sus crías.\n";
    }
};

// Clase Reptil
class Reptil : public Animal {
public:
    Reptil(int p, bool c = false) : Animal("Reptil", 3, p, c) {
        // El reptil necesita 3 unidades de comida al día
    }

    void mostrarDescripcion() {
        cout << "Un reptil tiene escamas y es de sangre fría.\n";
    }
};

// Clase Pez
class Pez : public Animal {
public:
    Pez(int p, bool c = false) : Animal("Pez", 1, p, c) {
        // El pez necesita 1 unidad de comida al día
    }

    void mostrarDescripcion() {
        cout << "Un pez vive en el agua, respira por branquias y nada con aletas.\n";
    }
};

// Clase Anfibio
class Anfibio : public Animal {
public:
    Anfibio(int p, bool c = false) : Animal("Anfibio", 2, p, c) {
        // El anfibio necesita 2 unidades de comida al día
    }

    void mostrarDescripcion() {
        cout << "Un anfibio puede vivir tanto en el agua como en la tierra.\n";
    }
};




int main()
{
    std::cout << "Hello World!\n";
}








