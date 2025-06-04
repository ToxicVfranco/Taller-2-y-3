#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(string id, string nombre, string tematica, string edicion)
    : Material(id, nombre, tematica), tematica(tematica), edicion(edicion) {}

void Revista::mostrarInfo() {
    cout << "REVISTA - ID: " << id << "\nNombre: " << titulo
         << "\nTematica: " << tematica << "\nEdicion: " << edicion
         << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
}

string Revista::getTipo() {
     return "Revista";
}
