#ifndef DVD_H
#define DVD_H

#include "Material.h"

using namespace std;

class DVD : public Material {
private:
    string director;
    int duracion;

public:
    DVD(string id, string titulo, string director, string genero, int duracion);
    void mostrarInfo() override;
    string getTipo() override;
};

#endif // DVD_H
