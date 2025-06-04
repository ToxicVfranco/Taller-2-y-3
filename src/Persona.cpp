#include "Persona.h"
#include "Material.h"
#include <iostream>

using namespace std;

Persona::Persona(string nombre, string id) : nombre(nombre), id(id) {}
Persona::~Persona() {}

string Persona::getNombre() { return nombre; }
string Persona::getId() { return id; }

bool Persona::puedePrestar() {
    return materialesPrestados.size() < 3;
}

void Persona::prestarMaterial(Material* material) {
    if (puedePrestar()) {
        material->prestar();
        materialesPrestados.push_back(material);
    } else {
        cout << "Limite de prestamos alcanzado (max 3)" << endl;
    }
}

void Persona::devolverMaterial(Material* material) {
    for (auto it = materialesPrestados.begin(); it != materialesPrestados.end(); ++it) {
        if ((*it)->getId() == material->getId()) {
            material->devolver();
            materialesPrestados.erase(it);
            break;
        }
    }
}

void Persona::mostrarMaterialesPrestados() {
    cout << "Materiales prestados a " << nombre << ":" << endl;
    for (auto material : materialesPrestados) {
        material->mostrarInfo();
        cout << "-----------------" << endl;
    }
}
