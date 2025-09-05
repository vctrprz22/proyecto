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



int main()
{
    std::cout << "Hello World!\n";
}






