#include "Material.h"
#include <iostream>

using namespace std;

Material::Material(string id, string titulo, string genero)
    : id(id), titulo(titulo), genero(genero), disponible(true) {}

Material::~Material() {}

//Getters

string Material::getId() {
    return id;
}

string Material::getTitulo() {
     return titulo;
}

string Material::getGenero() {
     return genero;
}



bool Material::estaDisponible() {
     return disponible;
}

void Material::prestar() {
     disponible = false;
}

void Material::devolver() {
     disponible = true;
}
