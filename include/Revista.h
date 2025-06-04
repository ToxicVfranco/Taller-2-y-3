#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"

using namespace std;

class Revista : public Material {
private:
    string tematica;
    string edicion;

public:
    Revista(string id, string nombre, string tematica, string edicion);
    void mostrarInfo() override;
    string getTipo() override;
};

#endif // REVISTA_H
