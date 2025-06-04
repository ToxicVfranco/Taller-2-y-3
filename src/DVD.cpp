#include "DVD.h"
#include <iostream>

using namespace std;

DVD::DVD(string id, string titulo, string director, string genero, int duracion)
    : Material(id, titulo, genero), director(director), duracion(duracion) {}

void DVD::mostrarInfo() {
    cout << "DVD - ID: " << id << "\nTitulo: " << titulo
         << "\nDirector: " << director << "\nGenero: " << genero
         << "\nDuracion: " << duracion << " min"
         << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
}

string DVD::getTipo() {
     return "DVD";
}
