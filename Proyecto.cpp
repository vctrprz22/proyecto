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
enum EstadoVida { Vivo, Muerto };
enum EstadoComida { BienAlimentado, Desnutrido };
enum EstadoSalud { Sano, Enfermo };

//Funciones al azar
int numeroAleatorio(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main()
{
    std::cout << "Hello World!\n";
}




