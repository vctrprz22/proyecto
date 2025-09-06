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



int main()
{
    std::cout << "Hello World!\n";
}







