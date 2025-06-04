#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

using namespace std;

class Material {
protected:
    string id;
    string titulo;
    string genero;
    bool disponible;

public:
    Material(string id, string titulo, string genero);
    virtual ~Material();

    string getId();
    string getTitulo();
    string getGenero();
    bool estaDisponible();

    void prestar();
    void devolver();

    virtual void mostrarInfo() = 0;
    virtual string getTipo() = 0;
};

#endif // MATERIAL_H
