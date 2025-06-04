#ifndef PERSONA_H
#define PERSONA_H

#include <vector>
#include <string>
#include "Material.h"

using namespace std;

class Persona {
protected:
    string nombre;
    string id;
    vector<Material*> materialesPrestados;

public:
    Persona(string nombre, string id);
    virtual ~Persona();

    string getNombre();
    string getId();

    bool puedePrestar();
    void prestarMaterial(Material* material);
    void devolverMaterial(Material* material);
    void mostrarMaterialesPrestados();
};

#endif // PERSONA_H
